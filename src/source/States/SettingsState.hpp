#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "State.hpp"
#include "GUI/SettingsMenu.hpp"
#include "GUI/DropDownList.hpp"


namespace States
{
class SettingsState :
	public State
{
//__________________________PUBLIC______________________________
public:
	//Constructors
	SettingsState() = delete;
	SettingsState(sf::RenderWindow& window,
				  std::stack<State*>& states,
				  std::map<const std::string, sf::Font*>& supported_fonts,
				  const std::map<const std::string, int>& supported_keys);
	virtual ~SettingsState();

	//Tech info
	virtual std::string getStringInfo() override;

	//Functions
	void pause() = delete;
	void unpause() = delete;

	//Update
	virtual void updateEvent(const sf::Event& event) override;
	virtual void update(const float& dt) override;

	//Render
	virtual void render(sf::RenderTarget& target) override;
//__________________________PRIVATE_____________________________
private:
	//Settings folder
	std::vector<sf::VideoMode> m_video_modes;

	//Members
	GUI::SettingsMenu m_settings_menu;
	sf::RectangleShape m_background;
	sf::Text m_title;

	//---------------------------------------------
	//Init
	virtual void inline initTextures() override;
	virtual void inline initKeybinds() override; //Delete
	void inline initBackground();

	//Functions
	void inline resetSettingsAllStates();

	//Update
	virtual void updateInput(const float& dt) override; //Delete
};
} // !namespace States
#endif // !SETTINGS_STATE_H