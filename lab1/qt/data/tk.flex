letter 				[a-zA-Z_]
digit				[0-9]
digits				{digit}(_?{digit})*
ws					\x20|\t
type				int|byte|string|float32|float64|uint|bool
keyword				break|default|func|interface|select|case|defer|go|map|struct|chan|else|goto|package|switch|const|fallthrough|if|range|type|continue|for|import|return|var
oper_punct			\+|&|\+=|&=|&&|==|!=|-|\||-=|\|=|\|\||<|<=|\[|\]|\*|\^|\*=|\^=|<-|>|>=|\{|\}|\/|<<|\/=|<<=|\+\+|=|:=|,|;|\%|>>|\%=|>>=|--|!|\.\.\.|\.|:|&\^|&\^=|~

identifier			{letter}({letter}|{digit})*
pack_identifier     {identifier}\.{identifier}
decimal_literal		0|-?[1-9](_?{digits})?
float_literal		-?{digits}\.{digits}?
string_literal		\"[^"\n]*\"
bool_literal		true|false
function_call 		(({pack_identifier}|{identifier}){ws}*)\(
function_def 		func{ws}+{identifier}{ws}*\({ws}*({identifier}({ws}+{type})?{ws}*(,{ws}*{identifier}({ws}+{type})?{ws}*)*)?\){ws}*{type}?
comment_line		\/\/.*
comment_multiline	\/\*
labeled_statement	(goto|break|continue){ws}+{identifier}
label				{identifier}{ws}*:
classic_operand		{pack_identifier}|{identifier}|{decimal_literal}|{float_literal}|{string_literal}|{bool_literal}

%{
char temp[1000];
int i = 0;
%}

%x FDEF
%x CMUL
%x LSTA
%x LBEL

%%
package.*|import{ws}*([^)]*)|\)|\]|\}														{}
\{																							{fprintf(yyout, "%s: %s\n", "operator", "{}");}
\[																							{fprintf(yyout, "%s: %s\n", "operator", "[]");}
case|default|import|package|else															{}
{label}																						{yyless(0); BEGIN(LBEL);}
{labeled_statement}																			{yyless(0); BEGIN(LSTA);}
{function_def}																				{fprintf(yyout, "%s: %s\n", "function defenition", yytext); yyless(0); BEGIN(FDEF);}
{function_call}																				{fprintf(yyout, "%s: %s%s\n", "function call", yytext, "...)");}
{keyword}																					{fprintf(yyout, "%s: %s\n", "operator", yytext);}
{type}																						{}
{classic_operand}																			{fprintf(yyout, "%s: %s\n", "operand", yytext);}
\(																							{fprintf(yyout, "%s: %s\n", "operator", "()");}
{comment_multiline}																			{BEGIN(CMUL);}

<FDEF>\{																					{yyless(0); BEGIN(INITIAL);}
<FDEF>{keyword}																				{}
<FDEF>{type}																				{}
<FDEF>{identifier}{ws}*\(																	{}
<FDEF>{identifier}																			{fprintf(yyout, "%s: %s\n", "operand", yytext);}

<CMUL>\*\/																					{BEGIN(INITIAL);}

<LSTA>{keyword}																				{fprintf(yyout, "%s: %s\n", "operator", yytext);}
<LSTA>{identifier}                             												{BEGIN(INITIAL);}

<LBEL>{identifier}																			{i = 0; while (yytext[i] != '\0') {temp[i] = yytext[i]; i++;} temp[i] = '\0';}
<LBEL>:/=                                                                      				{fprintf(yyout, "%s: %s\n", "operand", temp); yyless(0); BEGIN(INITIAL);}
<LBEL>:																						{BEGIN(INITIAL);}

<*>{oper_punct}																				{fprintf(yyout, "%s: %s\n", "operator", yytext);}
<*>{comment_line}																			{}
<*>.|\n 																					{}
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

