#include "StdAfx.h"
#include ".\differentiate.h"

/////////////////////////////////////////////////////////////////////////
// DifferentiateStack: takes the input stack and applies operators to operands 
/////////////////////////////////////////////////////////////////////////
CString DifferentiateStack(vector<ExpressionItem*>& vStack, int& nExpression)
{
	ExpressionItem *pQI = vStack[nExpression++];
	if(pQI->m_cOperator)
	{
		// get left operand
		CString u = vStack[nExpression]->GetInput();
		// get left operand differentiation
		CString du = DifferentiateStack(vStack, nExpression);
		// get right operand
		CString v = vStack[nExpression]->GetInput();
		// get right operand differentiation
		CString dv = DifferentiateStack(vStack, nExpression);

		if(du == '0')	// u is constant
			switch(pQI->m_cOperator)
			{
			case '-':	// d(u-v) = -dv
				pQI->m_strOutput = "(-"+dv+')';
				break;
			case '+':	// d(u+v) = dv
				pQI->m_strOutput = dv;
				break;
			case '*':	// d(u*v) = u*dv
				pQI->m_strOutput = u+'*'+dv;
				break;
			case '/':	// d(u/v) = (-u*dv)/v^2
				pQI->m_strOutput = "(-"+u+'*'+dv+")/("+v+")^2";
				break;
			case '^':	// d(u^v) = dv*u^v*ln(u)
				pQI->m_strOutput = dv+"*"+u+"^"+v+(u == 'e' ? "" : "*ln("+u+")");
				break;
			}
		else	if(dv == '0')	// v is constant
			switch(pQI->m_cOperator)
			{
			case '-':	// d(u-v) = du
			case '+':	// d(u+v) = du
				pQI->m_strOutput = du;
				break;
			case '*':	// d(u*v) = du*v
				pQI->m_strOutput = du+'*'+v;
				break;
			case '/':	// d(u/v) = du/v
				pQI->m_strOutput = '('+du+")/"+v;
				break;
			case '^':	// d(u^v) = v*u^(v-1)*du
				pQI->m_strOutput.Format("%s*%s^%s*%s", v, u, TrimFloat(atof(v)-1), du);
				break;
			}
		else
			switch(pQI->m_cOperator)
			{
			case '-':	// d(u-v) = du-dv
			case '+':	// d(u+v) = du+dv
				pQI->m_strOutput = '('+du+pQI->m_cOperator+dv+')';
				break;
			case '*':	// d(u*v) = u*dv+du*v
				pQI->m_strOutput = '('+u+'*'+dv+'+'+du+'*'+v+')';
				break;
			case '/':	// d(u/v) = (du*v-u*dv)/v^2
				pQI->m_strOutput = '('+du+'*'+v+'-'+u+'*'+dv+")/("+v+")^2";
				break;
			case '^':	// d(u^v) = v*u^(v-1)*du+u^v*ln(u)*dv
				pQI->m_strOutput = '('+v+'*'+u+"^("+v+"-1)*"+du+'+'+u+'^'+v+"*ln("+u+")*"+dv+')';
				break;
			}
	}
	else
		// get Expression differentiation
		pQI->GetDifferentiation();
	// return resultant differentiation
	return pQI->m_strOutput;
}

CString Differentiate(LPCSTR lpcsInput, CString& strStack, bool bOptimize /*= false*/)
{
	CString strInput = lpcsInput;
	// remove spaces
	strInput.Remove(' ');
	// make all characters lower case
	strInput.MakeLower();
	// Optimize "--"
	OptimizeSign(strInput);

	vector<ExpressionItem*> vStack;
	// parse input equation and fill stack with operators and operands
	if(FillStack(strInput, vStack) < 0)
		return "Invalid input";

	int nExpression = 0;
	// apply operators to operands
	CString strOutput = DifferentiateStack(vStack, nExpression);

	// loop to fill the stack string from the stack vector
	for(vector<ExpressionItem*>::iterator pQI = vStack.begin(); pQI != vStack.end(); pQI++)
	{
		if((*pQI)->m_cOperator)
			strStack += (*pQI)->m_cOperator + CString("\r\n");
		else
			strStack += "d("+(*pQI)->m_strInput+")/dx = "+(*pQI)->m_strOutput+"\r\n";

		// insert tabs in front of the item stack
		InsertTabs((*pQI)->m_strStack);
		strStack += (*pQI)->m_strStack;
		delete *pQI;
	}

	if(bOptimize == true)
		// optimize the equation from unneeded elements
		Optimize(strOutput);
	// return output differentiation
	return strOutput;
}

void ExpressionItem::GetDifferentiation()	
{
	int nIndex;
	if(m_nFunction != -1)
	{
		nIndex = m_strInput.Find('(');
		CString str = m_strInput.Mid(nIndex+1);
		// get the string between function parentheses
		str = str.Left(str.ReverseFind(')'));
		switch(m_nFunction)
		{
		case 0:		m_strOutput = d(str, m_strStack);			break;
		case 1:		m_strOutput = d_sin(str, m_strStack);		break;		
		case 2:		m_strOutput = d_cos(str, m_strStack);		break;
		case 3:		m_strOutput = d_tan(str, m_strStack);		break;
		case 4:		m_strOutput = d_sec(str, m_strStack);		break;
		case 5:		m_strOutput = d_cosec(str, m_strStack);		break;
		case 6:		m_strOutput = d_cot(str, m_strStack);		break;		
		case 7:		m_strOutput = d_sinh(str, m_strStack);		break;	
		case 8:		m_strOutput = d_cosh(str, m_strStack);		break;	
		case 9:		m_strOutput = d_tanh(str, m_strStack);		break;	
		case 10:	m_strOutput = d_sech(str, m_strStack);		break;	
		case 11:	m_strOutput = d_cosech(str, m_strStack);	break;	
		case 12:	m_strOutput = d_coth(str, m_strStack);		break;	
		case 13:	m_strOutput = d_asin(str, m_strStack);		break;	
		case 14:	m_strOutput = d_acos(str, m_strStack);		break;	
		case 15:	m_strOutput = d_atan(str, m_strStack);		break;	
		case 16:	m_strOutput = d_asec(str, m_strStack);		break;	
		case 17:	m_strOutput = d_acosec(str, m_strStack);	break;	
		case 18:	m_strOutput = d_acot(str, m_strStack);		break;	
		case 19:	m_strOutput = d_asinh(str, m_strStack);		break;	
		case 20:	m_strOutput = d_acosh(str, m_strStack);		break;	
		case 21:	m_strOutput = d_atanh(str, m_strStack);		break;	
		case 22:	m_strOutput = d_asech(str, m_strStack);		break;	
		case 23:	m_strOutput = d_acosech(str, m_strStack);	break;	
		case 24:	m_strOutput = d_acoth(str, m_strStack);		break;	
		case 25:	m_strOutput = d_sqrt(str, m_strStack);		break;	
		case 26:	m_strOutput = d_log10(str, m_strStack);		break;
		case 27:	m_strOutput = d_log(str, m_strStack);		break;
		case 28:	m_strOutput = d_ln(str, m_strStack);		break;
		case 29:	m_strOutput = d_sign(str, m_strStack);		break;
		case 30:	m_strOutput = d_abs(str, m_strStack);		break;
		}
		m_strOutput = (m_nSign == -1?"-":"")+m_strOutput;
	}
	else
	{
		// dx/dx = 1
		if(m_strInput == 'x' || m_strInput == "+x")
			m_strOutput = '1';
		else	if(m_strInput == "-x")
			m_strOutput = "-1";
		else	if(IsNumeric(m_strInput))
			// dc/dx = 0, where c is constant
			m_strOutput = '0';
		else
			// du/dx, where u is a function of x
			m_strOutput = 'd'+m_strInput+"/dx";
	}
}
