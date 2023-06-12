#include <string>

#include "Category.h"
#include "AbsProduct.h"

int Category::m_indent = 0;

Category::Category(std::string name)
	: AbsCatalogComponent(name)
{
}

Category::Category(const Category& mdd)
	: AbsCatalogComponent(mdd.m_name)
{
	// À compléter pour copier tous les éléments du catalogue contenus dans la catégorie
	for (auto it = mdd.cbegin(); it != mdd.cend(); ++it) {
		addCatalogComponent(*it);
	}
}

Category * Category::clone(void) const
{
	// À compléter pour construire un nouvel objet Category en appelant le constructeur de copie
	return new Category(*this); // Question : Est-ce que ceci va etre delete quand le unique_ptr qui en prend possession dans le addCatalogComponent est detruit?
}

AbsCatalogComponent& Category::addCatalogComponent(const AbsCatalogComponent & member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur de produits. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	m_products.push_back(CatalogComponentPtr(member.clone()));
	return *m_products.back();
}

CatalogComponentIterator Category::begin()
{
	return m_products.begin();
}

CatalogComponentIterator_const Category::cbegin() const
{
	return m_products.cbegin();
}

CatalogComponentIterator_const Category::cend() const
{
	return m_products.cend();
}

CatalogComponentIterator Category::end()
{
	return m_products.end();
}

void Category::deleteCatalogComponent(CatalogComponentIterator_const child)
{
	// À compléter pour éliminer de la catégorie l'élément auquel réfère l'itérateur
	m_products.erase(child);
}

void Category::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de la catégorie
	// VÉRIFIER
	m_products.clear();
}	

const AbsProduct* Category::findProduct(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans la catégorie à la recherche d'un produit
	// portant le nom reçu en argument. Si aucun produit n'est trouvé on retourne nullptr
	const AbsProduct* foundProduct = nullptr;
	
	for (auto&& element : m_products) {
		AbsProduct* product = dynamic_cast<AbsProduct*>(element.get());
		if (product != nullptr) {
			// Si product est bien un produit
			if (product->getName() == productName)
				return product;
		}
		else {
			// Si product est une Category
			foundProduct = element->findProduct(productName);
			if (foundProduct != nullptr)
				return foundProduct;
		}
	}
	return foundProduct;
}

std::ostream & Category::printToStream(std::ostream & o) const
{
	// À compléter pour imprimer sur un stream une catégorie et ses produits
	o << "Category: " << m_name << std::endl;
	m_indent++;
	for (auto it = m_products.cbegin(); it != m_products.cend(); ++it) {
		indent(o) << **it;
	}
	m_indent--;
	return o << std::endl;
}

std::ostream & Category::indent(std::ostream & o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
