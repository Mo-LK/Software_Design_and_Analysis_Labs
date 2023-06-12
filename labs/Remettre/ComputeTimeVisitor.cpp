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
	// It�re sur les enfants du composite et applique le visiteur � chaque enfant
 
	// Ceci est ce que le prof nous a donn� pour commencer, mais je l'ai modifi�:
	//for (auto it = composite.cbegin(); it != composite.cend(); ++it) {
	//	m_preparationTime += it->getDuration();
	//}

 	for (auto it = composite.begin(); it != composite.end(); ++it) {
		it->accept(*this);
	}
}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// Ajoute la dur�e de pr�paration de l'ingr�dient au temps total de pr�paration
	m_preparationTime += ingredient.getDuration();
}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// It�re sur les ingr�dients et applique le visiteur � chaque enfant
	// It�re sur chaque �tape et applique le visiteur � chaque �tape

	for (auto it = recipe.begin(); it != recipe.end(); ++it) {
		it->accept(*this);
	}

	for (auto it = recipe.begin_step(); it != recipe.end_step(); ++it) {
		it->accept(*this);
	}
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// Ajoute la dur�e de r�alisation de l'�tape au temps total de r�alisation
	m_realizationTime += step.getDuration();
}
