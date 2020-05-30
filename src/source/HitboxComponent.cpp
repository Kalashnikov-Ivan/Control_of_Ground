#include "HitboxComponent.hpp"

using namespace Components;

////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////
HitboxComponent::HitboxComponent(const sf::Sprite& sprite,
								 const sf::Vector2f&& offset_xy, const sf::Vector2f&& size_xy)
	: m_sprite(sprite),
	m_offset_xy(offset_xy),
	m_hitbox(size_xy)
{
	m_hitbox.setPosition(m_sprite.getPosition() + m_offset_xy);

	//Debug
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineThickness(1.f);
	m_hitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{
}

////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////
bool HitboxComponent::checkIntersect(const sf::FloatRect& f_rect)
{
	return m_hitbox.getGlobalBounds().intersects(f_rect);
}

void HitboxComponent::update()
{
	m_hitbox.setPosition(m_sprite.getPosition() + m_offset_xy);
}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(m_hitbox);
}