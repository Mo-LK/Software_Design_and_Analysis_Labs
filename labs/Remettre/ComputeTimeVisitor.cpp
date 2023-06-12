///////////////////////////////////////////////////////////
//  ComputeTimeVisitor.cpp
//  Implementation of the Class ComputeTimeVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "ComputeTimeVisitor.h"
#include "CompositeStep.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "SingleStep.h"

ComputeTimeVisitor::ComputeTimeVisitor()
	: m_preparationTime(0), m_realizationTime(0)
{
}

void ComputeTimeVisitor::processCompositeStep(CompositeStep& composite)
{
	// Itère sur les enfants du composite et applique le visiteur à chaque enfant
 
	// Ceci est ce que le prof nous a donné pour commencer, mais je l'ai modifié:
	//for (auto it = composite.cbegin(); it != composite.cend(); ++it) {
	//	m_preparationTime += it->getDuration();
	//}

 	for (auto it = composite.begin(); it != composite.end(); ++it) {
		it->accept(*this);
	}
}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// Ajoute la durée de préparation de l'ingrédient au temps total de préparation
	m_preparationTime += ingredient.getDuration();
}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// Itère sur les ingrédients et applique le visiteur à chaque enfant
	// Itère sur chaque étape et applique le visiteur à chaque étape

	for (auto it = recipe.begin(); it != recipe.end(); ++it) {
		it->accept(*this);
	}

	for (auto it = recipe.begin_step(); it != recipe.end_step(); ++it) {
		it->accept(*this);
	}
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// Ajoute la durée de réalisation de l'étape au temps total de réalisation
	m_realizationTime += step.getDuration();
}
