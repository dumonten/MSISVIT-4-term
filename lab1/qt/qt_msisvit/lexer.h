#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <map>
#include <QFile>
#include <QTextStream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace lexer
{
    char getData(std::map<QString, int> &, std::map<QString, int> &);
}


#endif
