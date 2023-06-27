
#include "version.h"
#include <llapi/mc/Player.hpp>
#include "Nlohmann/json.hpp"
#include <llapi/LoggerAPI.h>
#include <llapi/EventAPI.h>
#include <llapi/mc/Level.hpp>
#include <llapi/RegCommandAPI.h>

using nlohmann::json;
extern Logger logger;
using namespace std;

json make_op, make_player;

bool readJson() {
	json j;
	std::ifstream jfile("plugins/CommandPermChange/config.json");
	if (jfile) {
		jfile >> j;
		make_op = j["make_op"];
		make_player = j["make_player"];
		return true;
	}
	else {
		std::filesystem::create_directory("plugins/CommandPermChange");
		std::ofstream jfile("plugins/CommandPermChange/config.json");
		json j = json{ {"make_op", json::array({"tell", "me"})}, {"make_player", json::array()} };
		jfile << j.dump(4);
		logger.error("No config.json file was detected. Creating default..");
		return false;
	}

}



void PluginInit()
{
	if(!readJson()) readJson();
	logger.info("Command perms changed");

	Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
		for (string mkOP : make_op) {
			auto test = ev.mCommandRegistry->findCommand(mkOP);
			if(test) test->perm = CommandPermissionLevel::GameMasters;
		}
		for (string mkPl : make_player) {
			auto test = ev.mCommandRegistry->findCommand(mkPl);
			if(test) test->perm = CommandPermissionLevel::Any;
		}
		return true;
	});

	Event::PlayerCmdEvent::subscribe([](Event::PlayerCmdEvent ev) {

		string out = "§o§7[" + ev.mPlayer->getRealName() + "§r§7: \"/" + ev.mCommand + "\"]";
		for (auto it : Level::getAllPlayers())
			if (it->hasTag("showCommands"))
				it->sendText(out);
		return true;
	});

}