/*
<--------------------------------------------------------------------------->
 - Developer(s): Ghostcrawler336
 - Complete: 100%
 - ScriptName: 'Custom Event Commands' 
 - Comment: Untested
<--------------------------------------------------------------------------->
*/

#include "ScriptMgr.h"
#include "Language.h"

enum
{
	Event_Token = 1000,   // Define your event token here!
	ROOT = 39258, // Event Master Rooting spell

	// Spells
	event_spell = 6343,
	event_spell_1 = 12282,
	event_spell_2 = 12286,
	event_spell_3 = 12697,
	event_spell_4 = 23695
};

class emcommands : public CommandScript
{
public:
    emcommands() : CommandScript("emcommands") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand emCommandTable[] =

        {
        { "reward",	  SEC_MODERATOR,  true, &HandleEventReward,         "", NULL },
		{ "reward1",	  SEC_MODERATOR,  true, &HandleEventReward1,         "", NULL },
		{ "reward2",	  SEC_MODERATOR,  true, &HandleEventReward2,         "", NULL },
		{ "freeze",	  SEC_MODERATOR,  true, &Handlefreeze,         "", NULL },
		{ "unfreeze",	  SEC_MODERATOR,  true, &Handleunfreeze,         "", NULL },
		{ "port",	  SEC_MODERATOR,  true, &Handleport,         "", NULL },
		{ "learn",	  SEC_MODERATOR,  true, &Handlelearn,         "", NULL },
		{ "unlearn",	  SEC_MODERATOR,  true, &Handleunlearn,         "", NULL },
        { NULL,             0,                     false, NULL,          "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "em",	    SEC_MODERATOR,   true, NULL,      "",  emCommandTable},
	       { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }
static bool HandleEventReward(ChatHandler* handler, const char* args) // Gives one event token!
    {  
               Player* pPlayer = handler->GetSession()->GetPlayer();
               Player* plTarget = pPlayer->GetSelectedPlayer();
               plTarget->AddItem(Event_Token, 2);
               handler->PSendSysMessage("|cffB400B4Congratulations you have won yourself one event token!");
			   return true;
	}
static bool HandleEventReward1(ChatHandler * handler, const char * args) // Gives two event tokens!
    {          Player* pPlayer = handler->GetSession()->GetPlayer();
               Player* plTarget = pPlayer->GetSelectedPlayer();
               plTarget->AddItem(Event_Token, 2);
              handler->PSendSysMessage("|cffB400B4Congratulations you have won yourself two event token!");
			  return true;       
    }
static bool HandleEventReward2(ChatHandler* handler, const char* args) // Gives three event tokens!
    {
               Player* pPlayer = handler->GetSession()->GetPlayer();
               Player* plTarget = pPlayer->GetSelectedPlayer();
               plTarget->AddItem(Event_Token, 3);
               handler->PSendSysMessage("|cffB400B4Congratulations you have won yourself three event token!");
			   return true;
	}
static bool Handlefreeze(ChatHandler* handler, const char* args) // Handles the custom root command!
    {
               Player* pPlayer = handler->GetSession()->GetPlayer();
               Player* plTarget = pPlayer->GetSelectedPlayer();
               plTarget->CastSpell(pPlayer, ROOT, true);
			   handler->PSendSysMessage("|cffB400B4You have been frozen to make this event easier to handle!");
			   return true;
	}
static bool Handleunfreeze(ChatHandler* handler, const char* args) // Unaura the root spell!
    {
               Player* pPlayer = handler->GetSession()->GetPlayer();
               Player* plTarget = pPlayer->GetSelectedPlayer();
               plTarget->RemoveAura(ROOT);
			   handler->PSendSysMessage("|cffB400B4You're now unfrozen!");
			return true;
	}
static bool Handleport(ChatHandler* handler, const char* args) // Teleports the selected player to stormwind or org based on faction
    {
               Player* pPlayer = handler->GetSession()->GetPlayer();
               Player* plTarget = pPlayer->GetSelectedPlayer();
			    if (plTarget->GetTeam() == ALLIANCE)
               plTarget->TeleportTo(0, -8830.568359f, 624.444458f, 93.904198f, 3.853514f);
				else 
               plTarget->TeleportTo(1, 1598.709106f, -4397.028809f, 8.542884f, 3.697618f);		
				return true;
	}
static bool Handlelearn(ChatHandler* handler, const char* args) // Event Masters can use this command to learn per set spells inside the script. :)
    {
               Player* pPlayer = handler->GetSession()->GetPlayer();  
			   pPlayer->learnSpell(event_spell, true),
			   pPlayer->learnSpell(event_spell_1, true),
			   pPlayer->learnSpell(event_spell_2, true),
			   pPlayer->learnSpell(event_spell_3, true),
			   pPlayer->learnSpell(event_spell_4, true);
				return true;
	}
static bool Handleunlearn(ChatHandler* handler, const char* args) // Unlearn custom spells added.
   {
               Player* pPlayer = handler->GetSession()->GetPlayer();
			   pPlayer->removeSpell(event_spell, true),
			   pPlayer->removeSpell(event_spell_1, true),
			   pPlayer->removeSpell(event_spell_2, true),
			   pPlayer->removeSpell(event_spell_3, true),
			   pPlayer->removeSpell(event_spell_4, true);
			   pPlayer->removeSpell(event_spell, true);
				return true;
	}
};
void AddSC_emcommands()
{
    new emcommands();
}