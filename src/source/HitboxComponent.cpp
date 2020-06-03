#include "HitboxComponent.hpp"

using namespace Components;

////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////
HitboxComponent::HitboxComponent(sf::Sprite& sprite,
								 const sf::Vector2f& offset_basic,
								 const sf::Vector2f& size_xy,
								 const sf::Vector2f& scale)
	: m_sprite{ sprite },
	m_offset_basic{ offset_basic }, m_offset_move{ sf::Vector2f(0.f, 0.f) },
	m_hitbox{ size_xy }, m_default_size{ size_xy }
{
	m_hitbox.setPosition(m_sprite.getPosition() + m_offset_basic);
	m_hitbox.setScale(scale);

	//Debug
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineThickness(0.3f);
	m_hitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{
}

////////////////////////////////////////////////////////////
// Accessors
////////////////////////////////////////////////////////////
sf::Vector2f HitboxComponent::getDefaultSize() const
{
	return m_default_size;
}

////////////////////////////////////////////////////////////
// Modificators
////////////////////////////////////////////////////////////
void HitboxComponent::setPosition(const sf::Vector2f& position)
{
	m_hitbox.setPosition(position + m_offset_basic);
}


void HitboxComponent::setOffsetMove(const sf::Vector2f& offset)
{
	m_offset_move = offset;
}

void HitboxComponent::setRotation(const float& rotation)
{
	m_hitbox.setRotation(rotation);
}

void Components::HitboxComponent::setSize(const sf::Vector2f& size)
{
	m_hitbox.setSize(size);
}

////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////
bool HitboxComponent::checkIntersect(const sf::FloatRect& f_rect)
{
	return m_hitbox.getGlobalBounds().intersects(f_rect);
}

////////////////////////////////////////////////////////////
// Update and render
////////////////////////////////////////////////////////////
void HitboxComponent::update(const float& dt)
{
	m_hitbox.setPosition(m_sprite.getPosition() + m_offset_basic + m_offset_move);
}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(m_hitbox);
}
