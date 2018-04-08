#include "Lexer/Lexer.h"
#include "Lexer/Token/TokenInformation/TokenInformation.h"
#include <iostream>

#include <string>

const int REQUIRED_ARGC = 1;
const std::string NO_ARGUMENT_ERROR = "Error: source code is not specified";

int main(int argc, char * argv[])
{
	if (argc - 1 < REQUIRED_ARGC)
	{
		std::cerr << NO_ARGUMENT_ERROR << "\n";
		return EXIT_FAILURE;
	}
	std::string inputFileName = argv[1];
	Lexer lexer(inputFileName);
	TokenInformation tokenInformation;
	std::ofstream restoreFile(inputFileName + ".restore");
	std::ofstream tokensFile(inputFileName + ".tokens");
	StreamPosition outputFileStreamPosition;
	while (lexer.GetNextTokenInformation(tokenInformation))
	{
		StreamString const & streamString = tokenInformation.GetTokenStreamString();
		std::string const & streamStringString = streamString.string;
		StreamPosition const & streamPosition = streamString.position;
		long const & line = streamPosition.GetLine();
		long const & column = streamPosition.GetColumn();
		while (line > outputFileStreamPosition.GetLine())
		{
			restoreFile << "\n";
			tokensFile << "\n";
			outputFileStreamPosition.IncreaseLine();
			outputFileStreamPosition.SetColumn(1);
		}
		char const indentCharacter = outputFileStreamPosition.GetColumn() == 1 ? '\t' : ' ';
		while (column > outputFileStreamPosition.GetColumn())
		{
			restoreFile << indentCharacter;
			tokensFile << indentCharacter;
			outputFileStreamPosition.IncreaseColumn();
		}
		for (char ch : streamStringString)
		{
			restoreFile << ch;
			if (ch == '\n' || ch == '\r')
			{
				outputFileStreamPosition.IncreaseLine();
				outputFileStreamPosition.SetColumn(1);
			}
			else
			{
				outputFileStreamPosition.IncreaseColumn();
			}
		}
		tokensFile << "[" << TokenExtensions::ToString(tokenInformation.GetToken()) << "]";
	}
	return EXIT_SUCCESS;
}
