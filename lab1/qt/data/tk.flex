letter 				[a-zA-Z_]
digit				[0-9]
digits				{digit}(_?{digit})*
ws					\x20|\t
type				int|byte|string|float32|float64|uint
keyword				break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var
oper_punct			\+|&|\+=|&=|&&|==|!=|\(|\)|-|\||-=|\|=|\|\||<|<=|\[|\]|\*|\^|\*=|\^=|<-|>|>=|\{|\}|\/|<<|\/=|<<=|\+\+|=|:=|,|;|\%|>>|\%=|>>=|--|!|\.\.\.|\.|:|&\^|&\^=|~

identifier			{letter}({letter}|{digit})*
pack_identifier     {identifier}\.{identifier}
decimal_literal		0|[1-9](_?{digits})?
float_literal		{digits}\.{digits}?
string_literal		\"[^"\n]*\"
function_call 		(({pack_identifier}|{identifier}){ws}*)\(
function_def 		func{ws}+{identifier}{ws}*\({ws}*({identifier}{ws}+{type}?{ws}*(,{ws}*{identifier}{ws}+{type}?{ws}*)*)?\){ws}*{type}?
comment				\/\/.*

%%
package.*|import{ws}*([^)]*)|\)|\]|\}														{}
\{																							{fprintf(yyout, "%s: %s\n", "operator", "{}");}
\[																							{fprintf(yyout, "%s: %s\n", "operator", "[]");}
case|default|import|return|package|else														{}
{keyword}																					{fprintf(yyout, "%s: %s %s\n", "operator", yytext, "statement");}
{function_def}																				{}
{function_call}																				{fprintf(yyout, "%s: %s\n", "function call", yytext);}
{pack_identifier}|{identifier}|{decimal_literal}|{float_literal}|{string_literal}			{fprintf(yyout, "%s: %s\n", "operand", yytext);}
\(																							{fprintf(yyout, "%s: %s\n", "operator", "()");}
{oper_punct}																				{fprintf(yyout, "%s: %s\n", "operator", yytext);}
.|\n 																						{}
%%

int yywrap(){};
int main() {
	FILE *fin = fopen("/home/dumonten/Documents/GitHub/MSISVIT-4-term/lab1/qt/data/goexample.txt", "r");
	FILE *fout = fopen("/home/dumonten/Documents/GitHub/MSISVIT-4-term/lab1/qt/build_folder/tokens.txt", "w");
	yyin = fin;
	yyout = fout;
	yylex();
	fclose(fin);
	fclose(fout);
	return 0;
}

