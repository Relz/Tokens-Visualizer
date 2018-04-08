#ifndef LEXER_CONSTANT_H
#define LEXER_CONSTANT_H

#include "NumberSystem/NumberSystem.h"
#include "Token/Constant/Constant.h"
#include <string>
#include <vector>

static std::vector<std::string> const SCANNER_DELIMITERS {
	Constant::Comment::BLOCK_BEGINNING,
	Constant::Comment::LINE,
	Constant::Separator::SPACE,
	Constant::Separator::TAB,
	Constant::Separator::END_OF_LINE_LF,
	Constant::Separator::END_OF_LINE_CR,
	Constant::Operator::Comparison::EQUIVALENCE,
	Constant::Operator::Comparison::NOT_EQUIVALENCE,
	Constant::Operator::Comparison::MORE_OR_EQUIVALENCE,
	Constant::Operator::Comparison::LESS_OR_EQUIVALENCE,
	Constant::Operator::Comparison::MORE,
	Constant::Operator::Comparison::LESS,
	Constant::Operator::Assignment::ASSIGNMENT,
	Constant::Operator::Assignment::DIVISION_ASSIGNMENT,
	Constant::Operator::Assignment::MINUS_ASSIGNMENT,
	Constant::Operator::Assignment::MULTIPLY_ASSIGNMENT,
	Constant::Operator::Assignment::PLUS_ASSIGNMENT,
	Constant::Operator::Arithmetic::DIVISION,
	Constant::Operator::Arithmetic::MINUS,
	Constant::Operator::Arithmetic::MULTIPLY,
	Constant::Operator::Arithmetic::PLUS,
	Constant::Separator::COLON,
	Constant::Separator::COMMA,
	Constant::Separator::DOT,
	Constant::Separator::SEMICOLON,
	Constant::Parentheses::QUOTE_STRING,
	Constant::Parentheses::DOUBLE_QUOTE_STRING,
	Constant::Parentheses::SQUARE_BRACKET.LEFT,
	Constant::Parentheses::SQUARE_BRACKET.RIGHT,
	Constant::Parentheses::ROUND_BRACKET.LEFT,
	Constant::Parentheses::ROUND_BRACKET.RIGHT,
	Constant::Parentheses::CURLY_BRACKET.LEFT,
	Constant::Parentheses::CURLY_BRACKET.RIGHT,
};

static NumberSystem const DEFAULT_NUMBER_SYSTEM = NumberSystem::TEN;

#endif //LEXER_CONSTANT_H
