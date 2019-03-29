#include <string>
#include <cassert>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	string countOfAtoms(string formula) {
		// 碰到左括号进入递归，碰到右括号返回
		int pos = 0;
		map<string, int> m;
		parse(formula, pos, m);

		string result;
		for (pair<string, int> a : m)
			result += a.first + (a.second == 1 ? "" : to_string(a.second));

		return result;
	}

	void parse(string& formula, int& pos, map<string, int>& result)
	{
		while (pos < formula.size())
		{
			if (formula[pos] == '(')
			{
				++pos;
				map<string, int> temp;
				parse(formula, pos, temp);
				for (pair<string, int> a : temp)
					result[a.first] += a.second;
			}

			else if (formula[pos] == ')')
			{
				++pos;
				int i = pos;
				while (pos < formula.size() && isdigit(formula[pos]))
					pos++;

				// 将括号后面紧跟的数字获取
				string multipleString = formula.substr(i, pos - i);
				int multiple = multipleString.empty() ? 1 : stoi(multipleString);
				for (pair<string, int> a : result)
					result[a.first] *= multiple;
				return;
			}
			else
			{
				int i = pos++;
				while (pos < formula.size() && islower(formula[pos]))
					pos++;

				// 获取元素
				string element = formula.substr(i, pos - i);
				i = pos;
				while (pos < formula.size() && isdigit(formula[pos]))
					pos++;

				// 将元素后面紧跟的数字获取
				string count = formula.substr(i, pos - i);
				result[element] += count.empty() ? 1 : stoi(count);
			}
		}
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line = "((Bi16LrSc30As49As23La13La(Ba21Re28BkRf40DbP29SeSe41La27Cn16)48(TcRn)49(Sb28Ti4Po35Mn16)21(Ta36Tl2Br5Dy21S41)6(Bh37Li36O20Tb48)24Cr43Pd11Pu39OgYb43Zr35FmHe44(Rh35BiLaCf4RnHLi10RgLuRg)3(Cn15PbS44Nd18)8)25((Hs11B41Rf46)20(At48Te45)32(Cs15Mt19OgHs34Ts5La33Ga23Np50Dy33O24)4)13((Po21ZnPdK27Pm16TlCo34Nd30Y4N)16(Nh2BaNa28Ga15LuAl38)17(Rb23ReRf2Rf33I32Te48Bh)50(Cf37Ne32W33BeRgIr21Cs34Mc17Zn43)43(Ho23ArEs38Er40Tb8DyIn41Tc36Hg21Cl9)42(Y8B25Ts16S10Fr2Lv22Po6)2(Zn46N34Ds7Sg20HoRf31P25ZrIHo22)40(FeRh50Kr9ThPt49)37(TaLrKr35Kr12SrCd26Xe28Mt26CnFl)43)23)17";
	string formula = stringToString(line);

	string ret = Solution().countOfAtoms(formula);

	string out = (ret);
	cout << out << endl;
	return 0;
}