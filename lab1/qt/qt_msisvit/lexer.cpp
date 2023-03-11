#include "lexer.h"

char lexer::getData(std::map<QString, int> &operators, std::map<QString, int> &operands)
{
    system("flex /home/dumonten/Documents/GitHub/MSISVIT-4-term/lab1/qt/data/tk.flex");
    system("gcc /home/dumonten/Documents/GitHub/MSISVIT-4-term/lab1/qt/build_folder/lex.yy.c");
    system("./a.out");

    QFile file("/home/dumonten/Documents/GitHub/MSISVIT-4-term/lab1/qt/build_folder/tokens.txt");

    if (!file.open(QIODevice::ReadOnly))
        return -1;

    QTextStream stream(&file);
    while (!stream.atEnd())
    {
       std::string str = (stream.readLine()).toStdString();
       int position;
       QString token;
       if ((position = str.find("operand: ")) != -1)
       {
           token = QString::fromStdString(str.substr(position + 9));
           operands[token]++;
       }
       else if ((position = str.find("operator: ")) != -1)
       {
          token = QString::fromStdString(str.substr(position + 10));
          operators[token]++;
       }
       else if ((position = str.find("function call: ")) != -1)
       {
           token = QString::fromStdString(str.substr(position + 15));
           operators[token]++;
           operands[token]++;
       }
       else if ((position = str.find("function defenition: func ")) != -1)
       {
           QString temp = QString::fromStdString(str.substr(position + 26));
           for (auto i : temp)
           {
               if (i == "(")
                   break;
               token += i;
           }
           token += "(...)";
           operators[token]++;
       }
    }
    file.close();
    return 1;
}
