/*
==============================================================================

  This file was auto-generated by the Introjucer!

  It contains the basic startup code for a Juce application.

==============================================================================
*/

#ifndef __PLUGINEDITOR_H_8FBA87C0__
#define __PLUGINEDITOR_H_8FBA87C0__

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//#include "LkjbLookAndFeels.h"
#include "GuiLookAndFeel.h"

class ModalCallback;

//==============================================================================
/**
*/
class LuftikusAudioProcessorEditor  : public AudioProcessorEditor,
	                                  public Slider::Listener,
									  public ComboBox::Listener,
									  public Timer,
									  public Button::Listener,
									  public TooltipClient
{
public:

	LuftikusAudioProcessorEditor (LuftikusAudioProcessor* ownerFilter, LuftikusAudioProcessor::GUIType type);
	~LuftikusAudioProcessorEditor();

  //==============================================================================
  // This is just a standard Juce paint method...
	void resized();
	void paint (Graphics& g);

	void timerCallback();

	void sliderValueChanged (Slider* slider);
	void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
	void buttonClicked (Button* button);

	void mouseDown(const MouseEvent& e);

	String getTooltip();
	void modalReturn(int returnValue);

private:


	class ModalCallback : public ModalComponentManager::Callback
	{
	public:
		ModalCallback(LuftikusAudioProcessorEditor* parent_)
			: parent(parent_)
		{
		}

		void modalStateFinished(int returnValue)
		{
			if (parent != nullptr)
				parent->modalReturn(returnValue);
		}
	private:
		LuftikusAudioProcessorEditor* parent;
	};

	void initLuftikus();
	void initLkjb();
	void initGui();

	void resizedLuftikus();
	void resizedLkjb();
	void resizedGui();

	void paintLuftikus(Graphics& g);
	void paintLkjb(Graphics& g);
	void paintGui(Graphics& g);

	void updateSliders();

	void updateSlidersLuftikus();
	void updateSlidersLkjb();
	void updateSlidersGui();

	void timerCallbackLuftikus();
	void timerCallbackLkjb();
	void timerCallbackGui();

	void updateTooltipState();

	LuftikusAudioProcessor* Proc;

	const LuftikusAudioProcessor::GUIType guiType;

	//LuftikusSlider luftikusSliders[EqDsp::kNumTypes];
	//LkjbSlider lkjbSliders[EqDsp::kNumTypes];
	GuiSlider guiSliders[EqDsp::kNumTypes];

	Label labels[EqDsp::kNumTypes];
	ComboBox type;

	ToggleButton mastering;
	ToggleButton analog;
	ToggleButton keepGain;

	//ToggleButton showTooltips;

	ToggleButton types[EqDsp::kNumHighSelves];

	//LuftikusSlider luftikusMasterVol;
	//LkjbSlider lkjbMasterVol;
	GuiSlider guiMasterVol;

	//ToggleButton guiSelector[LuftikusAudioProcessor::kNumTypes];

	Label masterVolLabel;

	Image background;
	//Image bgInfo;
	//Image luftikus;

	//LkjbLookAndFeel lkjbLookAndFeel; 
	//LuftikusLookAndFeel luftikusLookAndFeel;
	GuiLookAndFeel guiLookAndFeel;

	ScopedPointer<TooltipWindow> tooltips;

	ModalCallback* modalCallback;
	ScopedPointer<PopupMenu> showTooltips;

	//bool showInfo;

	JUCE_DECLARE_NON_COPYABLE(LuftikusAudioProcessorEditor)
};



#endif  // __PLUGINEDITOR_H_8FBA87C0__
