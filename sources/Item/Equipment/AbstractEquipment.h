#pragma once

#include "../Item.h"

enum EquipmentType {WEAPON, ARMOR};
enum ArmorType {NONE, HEAD, BOOTS, LEGS, BODY};

struct Penetration {
    float sharp, blunt, heat;
};


class AbstractEquipment: public Item {
private:
    EquipmentType equipmentType;
    ArmorType armorType;


    struct {
        int maxHitPoints, hitPoints, mass;
    } commonInfo;

    struct {
        Penetration penetration;
    } armorInfo;

    struct {
        float damage;
    } weaponInfo;
public:
    AbstractEquipment();
    AbstractEquipment(std::string name, std::string description);
    ~AbstractEquipment();

    void setEquipmentType(EquipmentType newType);
    void setArmorType(ArmorType newType);

    void setHitPoints(int newHitPoints);
    void setMaxHitPoints(int newMaxHitPoints);
    void setMass(int newMass);
    void setPenetration(Penetration newPenetration);
    void setDamage(float newDamage);
};