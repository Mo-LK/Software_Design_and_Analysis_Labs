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
	// Décompose la durée en nombre de jours, heures, minutes et secondes
	// retourne le résultat de la décomposition dans un objet time_decomposition
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
	// Insère la stratégie dans le registre des stratégies de la classe TimeFormater
	TimeFormater::getInstance().registerFormatStrategy(id, strategy);
}
