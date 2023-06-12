///////////////////////////////////////////////////////////
//  NumericFormatStrategy.cpp
//  Implementation of the Class NumericFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "NumericFormatStrategy.h"

NumericFormatStrategy NumericFormatStrategy::instance;

NumericFormatStrategy::NumericFormatStrategy()
	: FormatStrategy(NumericFormat)
{
}

std::string NumericFormatStrategy::format(int time) const 
{
	// Décompose la durée et construit une chaine avec en format numérique
	auto [days, hours, minutes, seconds] = decomposeTime(time);
	return std::string(
           std::to_string(days) + ":" +
           std::to_string(hours) + ":" +
           std::to_string(minutes) + ":" +
           std::to_string(seconds)
           );
}