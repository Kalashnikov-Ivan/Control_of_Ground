#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "stdHeader.hpp"

#include "Button.hpp"
#include "Menu.hpp"

namespace GUI
{
class PauseMenu :
	public Menu
{
public:
	//Constructors
	PauseMenu(sf::RenderWindow& window, sf::Font& main_font,
			  std::map<const std::string, sf::Font*>& supported_fonts);
	~PauseMenu();

	//Update
	void update(const sf::Vector2f& mouse_pos, const float& dt);

	//Render
	void render(sf::RenderTarget& target);

private:
	//Refs
	std::map<const std::string, sf::Font*>& m_supported_fonts;

	//Members
	sf::RectangleShape m_background;
	sf::RectangleShape m_container;

	sf::Text m_title;

	void initBackground();
	virtual void initButtons() override;

	//Update
	virtual void updateButtons(const sf::Vector2f& mouse_pos, const float& dt) override;
};
} // !namespace GUI
#endif // !PAUSE_MENU_H