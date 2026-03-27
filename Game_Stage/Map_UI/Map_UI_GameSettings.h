#pragma once
#include "..\Utilities/Button.h"
class Map_UI_GameSettings
{
private:
	Map_UI* m_MapUI;
	Game* m_game;
public:
	Button* UI_Element_GameSettingsButton;

	// Settings toggle states
	bool SoundEnabled = true;
	bool MusicEnabled = true;
	bool ShowBalloons = true;
	bool ShowShadows = true;
	bool InteractionEnabled = true;

	// Toggle buttons (using resource GFX 2,27 like EndlessClient)
	Button* BT_Toggle_Sound;
	Button* BT_Toggle_Music;
	Button* BT_Toggle_Balloons;
	Button* BT_Toggle_Shadows;
	Button* BT_Toggle_Interaction;

	Map_UI_GameSettings(Map_UI* m_MapUI, Game* m_Game);
	void Update();
	void Render(float depth);
	~Map_UI_GameSettings();
};

