#pragma once

#include <string>
#include <string_view>

class AbstractPlayer;

enum ItemType { ITEM, EQUIPMENT };

class Item {
private:
    std::string name;
    std::string description;
    ItemType type;
public:
    Item();
    Item(std::string name, std::string description);
    Item(std::string name, std::string description, ItemType type);
    ~Item();

    void setName(std::string newName);
    void setDescription(std::string newDescription);

    virtual void use(AbstractPlayer* ply) = 0;

    std::string_view getName();
    std::string_view getDescription();
};
