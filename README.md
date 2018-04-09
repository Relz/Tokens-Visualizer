# Tokens Visualizer

Программа использует [лексический анализатор Recode](https://github.com/Relz/Lexer).
В качестве входного параметра выступает путь до <file_name>.recode файла. На выходе два файла:
1. <file_name>.recode.restore: восстановленный исходный код по токенам;
2. <file_name>.recode.tokens: токены, расставленные по позициям соответстующих значений в исходном коде.

[Пример входного файла](https://github.com/Relz/Lexer/blob/master/program.recode)
