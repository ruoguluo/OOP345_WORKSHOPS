//	program    : Utilities.cpp
//	programmer : Yathavan, Parameshwaran
//	date       : February 26, 2019
//	professor  : Chris, Szalwinski

#include <iostream>
#include "Utilities.h"

namespace sict
{
	//default constructor
	Utilities::Utilities()
	{
		setDelimiter('\0');
	}

	//destructor
	Utilities::~Utilities()
	{
		delete[]this->myToken;
		this->myToken = nullptr;
	}

	//copy constructor
	Utilities::Utilities(const Utilities & incomingObj)
	{
		*this = incomingObj;
	}

	//copy assignment operator
	Utilities & Utilities::operator=(const Utilities & incomingObj)
	{
		if (this != &incomingObj)
		{
			this->myDelim = incomingObj.myDelim;
			this->numOfTokens = incomingObj.numOfTokens;

			delete[]myToken;
			if (incomingObj.myToken != nullptr)
			{
				for (int index = 0; index < incomingObj.numOfTokens; index++)
				{
					this->myToken[index] = incomingObj.myToken[index];
				}
			}
			else
			{
				myToken = nullptr;
			}
		}
		return *this;
	}


	//move constructor
	Utilities::Utilities(Utilities && incomingObj)
	{
		*this = std::move(incomingObj);
	}

	//move assignment operator
	Utilities & Utilities::operator=(Utilities && incomingObj)
	{
		if (this != &incomingObj)
		{
			this->myDelim = incomingObj.myDelim;
			this->numOfTokens = incomingObj.numOfTokens;

			incomingObj.myDelim = '\0';
			incomingObj.numOfTokens = 0;

			delete[]this->myToken;
			if (incomingObj.myToken != nullptr)
			{
				this->myToken = incomingObj.myToken;
				incomingObj.myToken = nullptr;
			}
			else
			{
				this->myToken = nullptr;
			}
		}
		return *this;
	}

	//extracts tokens based on incoming params
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos)
	{
		std::string tempStr;
		
		size_t positionOfDelim = str.find(getDelimiter());
		tempStr = str.substr(next_pos, positionOfDelim);
		if (tempStr.empty())
			throw("Exception occured in extractToken!");
		setFieldWidth(tempStr.length());
		return tempStr;
	}

	//returns local delimiter character
	const char Utilities::getDelimiter() const
	{
		return this->myDelim;
	}

	//returns field width for current object
	size_t Utilities::getFieldWidth() const
	{
		return this->myFieldWidth;
	}

	//sets delimiter character based on incoming param
	void Utilities::setDelimiter(const char d)
	{
		myDelim = d;
	}

	//sets field width for current object based on incoming param
	void Utilities::setFieldWidth(size_t t)
	{
		myFieldWidth = t > myFieldWidth ? t : myFieldWidth;		
	}
}