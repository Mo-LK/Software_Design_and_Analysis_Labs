///////////////////////////////////////////////////////////
//  FormatStrategy.cpp
//  Implementation of the Class FormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FormatStrategy.h"
#include "TimeFormater.h"

FormatStrategy::FormatStrategy(std::string id)
{
	registerFormatStrategy(id, this);
}

FormatStrategy::time_decomposition FormatStrategy::decomposeTime(int time) const
{
	// D�compose la dur�e en nombre de jours, heures, minutes et secondes
	// retourne le r�sultat de la d�composition dans un objet time_decomposition
	int days = time / 86'400;
	int reminder = time % 86'400;
	int hours = reminder / 3600;
	reminder %= 3600;
	int minutes = reminder / 60;
	int seconds = reminder % 60;

	return time_decomposition(days, hours, minutes, seconds);
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// Ins�re la strat�gie dans le registre des strat�gies de la classe TimeFormater
	TimeFormater::getInstance().registerFormatStrategy(id, strategy);
}
