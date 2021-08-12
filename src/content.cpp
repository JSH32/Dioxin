#include "content.h"

#include <SFML/Graphics.hpp>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <cmrc/cmrc.hpp>
CMRC_DECLARE(content);

inline bool endsWith(const std::string& value, const std::string& ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

/**
 * @brief Direct underlying access to game files
 */
namespace files {
    static cmrc::embedded_filesystem filesystem = cmrc::content::get_filesystem();

    static std::string getFileAsString(cmrc::file file) {
        return std::string(file.begin(), file.end());
    }

    static sf::Texture getFileAsTexture(cmrc::file file) {
        sf::Texture texture;
        texture.loadFromMemory(reinterpret_cast<void*>(const_cast<char*>(&*file.begin())), file.size());
        
        return texture;
    }

    static void* getFile(cmrc::file file) {
        return reinterpret_cast<void*>(const_cast<char*>(&*file.begin()));
    }
}

Content::Content() {
    // Game assets
    {
        auto iterator = files::filesystem.iterate_directory("assets");
        for (auto it = iterator.begin(); it != iterator.end(); it++) {
            cmrc::directory_entry file = (*it);
            if (file.is_file())
                textureMap[file.filename()] = files::getFileAsTexture(files::filesystem.open("assets/" + file.filename()));
        }
    }

    // Game items
    {
        auto iterator = files::filesystem.iterate_directory("items");
        for (auto it = iterator.begin(); it != iterator.end(); it++) {
            cmrc::directory_entry file = (*it);
            if (file.is_file()) {
                if (!endsWith(file.filename(), ".json")) continue;

                auto item = json::parse(files::getFileAsString(files::filesystem.open("items/" + file.filename())));

                bool placeable = item["placeable"].get<bool>();

                std::optional<std::string> block;
                if (placeable)
                    block.emplace(item["block"].get<std::string>());

                itemMap.insert(std::pair(item["id"].get<std::string>(), Item(
                    item["id"].get<std::string>(),
                    item["name"].get<std::string>(),
                    item["description"].get<std::string>(),
                    placeable,
                    block,
                    textureMap[item["texture"].get<std::string>()]
                )));
            }
        }
    }

    // Blocks
    {
        auto iterator = files::filesystem.iterate_directory("blocks");
        for (auto it = iterator.begin(); it != iterator.end(); it++) {
            cmrc::directory_entry file = (*it);
            if (file.is_file()) {
                if (!endsWith(file.filename(), ".json")) continue;

                auto block = json::parse(files::getFileAsString(files::filesystem.open("blocks/" + file.filename())));
                bool destructible = block["destructible"].get<bool>();

                std::optional<std::string> item;
                if (destructible)
                    item.emplace(block["item"].get<std::string>());

                blockMap.insert(std::pair(block["id"].get<std::string>(), Block(
                    block["id"].get<std::string>(),
                    item,
                    textureMap[block["texture"].get<std::string>()]
                )));
            }
        }
    }
}