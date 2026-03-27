#include "..\..\stdafx.h"
#include "Map_UI.h"
#include "..\game.h"


Map_UI_GameSettings::Map_UI_GameSettings(Map_UI* m_UIElement, Game* p_Game)
{
	this->m_MapUI = m_UIElement;
	this->m_game = p_Game;
	this->UI_Element_GameSettingsButton = new Button(this->m_game, 590, 410, 0, 171, 36, 19, false, this->m_game->ResourceManager->GetResource(2, 25, false));

	// Toggle buttons positioned relative to the settings panel (matching EndlessClient layout)
	// Each button is at column offset + row offset from the panel origin (102, 330)
	int panelX = 101;
	int panelY = 331;
	this->BT_Toggle_Sound = new Button(this->m_game, panelX + 215, panelY + 25, 0, 0, 19, 15, false, this->m_game->ResourceManager->GetResource(2, 27, true));
	this->BT_Toggle_Music = new Button(this->m_game, panelX + 215, panelY + 43, 0, 0, 19, 15, false, this->m_game->ResourceManager->GetResource(2, 27, true));
	this->BT_Toggle_Balloons = new Button(this->m_game, panelX + 215, panelY + 61, 0, 0, 19, 15, false, this->m_game->ResourceManager->GetResource(2, 27, true));
	this->BT_Toggle_Shadows = new Button(this->m_game, panelX + 215, panelY + 79, 0, 0, 19, 15, false, this->m_game->ResourceManager->GetResource(2, 27, true));
	this->BT_Toggle_Interaction = new Button(this->m_game, panelX + 215, panelY + 97, 0, 0, 19, 15, false, this->m_game->ResourceManager->GetResource(2, 27, true));
}

void Map_UI_GameSettings::Update()
{
	this->UI_Element_GameSettingsButton->Update(this->m_MapUI->MouseX, this->m_MapUI->MouseY, this->m_MapUI->MousePressed);
	if (this->UI_Element_GameSettingsButton->MouseClickedOnElement())
	{
		this->m_MapUI->SetStage(Map_UI::UI_ElementStage::UI_Element_GameSettings, 0);
	}
	switch (this->m_MapUI->UI_Stage)
	{
	case(Map_UI::UI_ElementStage::UI_Element_GameSettings):
	{
		this->BT_Toggle_Sound->Update(this->m_MapUI->MouseX, this->m_MapUI->MouseY, this->m_MapUI->MousePressed);
		this->BT_Toggle_Music->Update(this->m_MapUI->MouseX, this->m_MapUI->MouseY, this->m_MapUI->MousePressed);
		this->BT_Toggle_Balloons->Update(this->m_MapUI->MouseX, this->m_MapUI->MouseY, this->m_MapUI->MousePressed);
		this->BT_Toggle_Shadows->Update(this->m_MapUI->MouseX, this->m_MapUI->MouseY, this->m_MapUI->MousePressed);
		this->BT_Toggle_Interaction->Update(this->m_MapUI->MouseX, this->m_MapUI->MouseY, this->m_MapUI->MousePressed);

		if (this->BT_Toggle_Sound->MouseClickedOnElement())
		{
			this->SoundEnabled = !this->SoundEnabled;
			this->BT_Toggle_Sound->Deactivate();
		}
		if (this->BT_Toggle_Music->MouseClickedOnElement())
		{
			this->MusicEnabled = !this->MusicEnabled;
			this->BT_Toggle_Music->Deactivate();
		}
		if (this->BT_Toggle_Balloons->MouseClickedOnElement())
		{
			this->ShowBalloons = !this->ShowBalloons;
			this->BT_Toggle_Balloons->Deactivate();
		}
		if (this->BT_Toggle_Shadows->MouseClickedOnElement())
		{
			this->ShowShadows = !this->ShowShadows;
			this->BT_Toggle_Shadows->Deactivate();
		}
		if (this->BT_Toggle_Interaction->MouseClickedOnElement())
		{
			this->InteractionEnabled = !this->InteractionEnabled;
			this->BT_Toggle_Interaction->Deactivate();
		}
		break;
	}
	default:
		return;
	}
}

void Map_UI_GameSettings::Render(float depth)
{
	this->UI_Element_GameSettingsButton->Draw();
	switch (this->m_MapUI->UI_Stage)
	{
	case(Map_UI::UI_ElementStage::UI_Element_GameSettings):
	{
		// Draw background
		this->m_game->Draw(this->m_game->ResourceManager->GetResource(2, 47, false), 101, 331, sf::Color(255, 255, 255, 255), 0, 0, -1, -1, sf::Vector2f(1, 1), depth);

		int panelX = 101;
		int panelY = 331;

		// Draw setting labels with their current state
		sf::Color labelCol = sf::Color(240, 240, 199, 255);
		sf::Color valueCol = sf::Color(222, 222, 222, 255);

		this->m_game->DrawTextW("Sound", panelX + 117, panelY + 27, labelCol, 9, false, depth, 0);
		this->m_game->DrawTextW(this->SoundEnabled ? "ON" : "OFF", panelX + 175, panelY + 27, valueCol, 9, false, depth, 0);

		this->m_game->DrawTextW("Music", panelX + 117, panelY + 45, labelCol, 9, false, depth, 0);
		this->m_game->DrawTextW(this->MusicEnabled ? "ON" : "OFF", panelX + 175, panelY + 45, valueCol, 9, false, depth, 0);

		this->m_game->DrawTextW("Chat Bubbles", panelX + 117, panelY + 63, labelCol, 9, false, depth, 0);
		this->m_game->DrawTextW(this->ShowBalloons ? "ON" : "OFF", panelX + 175, panelY + 63, valueCol, 9, false, depth, 0);

		this->m_game->DrawTextW("Shadows", panelX + 117, panelY + 81, labelCol, 9, false, depth, 0);
		this->m_game->DrawTextW(this->ShowShadows ? "ON" : "OFF", panelX + 175, panelY + 81, valueCol, 9, false, depth, 0);

		this->m_game->DrawTextW("Interaction", panelX + 117, panelY + 99, labelCol, 9, false, depth, 0);
		this->m_game->DrawTextW(this->InteractionEnabled ? "ON" : "OFF", panelX + 175, panelY + 99, valueCol, 9, false, depth, 0);

		// Draw toggle buttons
		this->BT_Toggle_Sound->Draw(depth);
		this->BT_Toggle_Music->Draw(depth);
		this->BT_Toggle_Balloons->Draw(depth);
		this->BT_Toggle_Shadows->Draw(depth);
		this->BT_Toggle_Interaction->Draw(depth);
		break;
	}
	default:
		return;
	}
}

Map_UI_GameSettings::~Map_UI_GameSettings()
{

}
