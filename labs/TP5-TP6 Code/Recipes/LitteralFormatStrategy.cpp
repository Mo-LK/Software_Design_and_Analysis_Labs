///////////////////////////////////////////////////////////
//  LitteralFormatStrategy.cpp
//  Implementation of the Class LitteralFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "LitteralFormatStrategy.h"
#include "TimeFormater.h"

LitteralFormatStrategy LitteralFormatStrategy::instance;


LitteralFormatStrategy::LitteralFormatStrategy()
	: FormatStrategy(LitteralFormat)
{
}

std::string LitteralFormatStrategy::format(int time) const 
{
	// Décompose la durée et construit une chaine avec en format litéral
	auto [days, hours, minutes, seconds] = decomposeTime(time);
	return std::string(
           std::to_string(days) + " days " + 
           std::to_string(hours) + " hours " + 
           std::to_string(minutes) + " minutes " + 
           std::to_string(seconds) + " secondes "
           );
}