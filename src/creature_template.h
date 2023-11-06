#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class creature_template {
public:
    int TotalNumValues = 65;
    long long int entry = 0;
    long long int difficulty_entry_1 = 0;
    long long int difficulty_entry_2 = 0;
    long long int difficulty_entry_3 = 0;
    long long int KillCredit1 = 0;
    long long int KillCredit2 = 0;
    long long int modelid1 = 0;
    long long int modelid2 = 0;
    long long int modelid3 = 0;
    long long int modelid4 = 0;
    string name = "";
    string subname = "";
    string IconName = "";
    long long int gossip_menu_id = 0;
    long long int minlevel = 0;
    long long int maxlevel = 0;
    long long int exp = 0;
    long long int faction = 0;
    long long int npcflag = 0;
    long long int speed_walk = 0;
    double speed_run = 0;
    long long int speed_swim = 0;
    long long int speed_flight = 0;
    long long int detection_range = 0;
    long long int scale = 0;
    long long int rank = 0;
    long long int dmgschool = 0;
    double DamageModifier = 0;
    long long int BaseAttackTime = 0;
    long long int RangeAttackTime = 0;
    long long int BaseVariance = 0;
    long long int RangeVariance = 0;
    long long int unit_class = 0;
    long long int unit_flags = 0;
    long long int unit_flags2 = 0;
    long long int dynamicflags = 0;
    long long int family = 0;
    long long int trainer_type = 0;
    long long int trainer_spell = 0;
    long long int trainer_class = 0;
    long long int trainer_race = 0;
    long long int type = 0;
    long long int type_flags = 0;
    long long int lootid = 0;
    long long int pickpocketloot = 0;
    long long int skinloot = 0;
    long long int PetSpellDataId = 0;
    long long int VehicleId = 0;
    long long int mingold = 0;
    long long int maxgold = 0;
    string AIName = "";
    long long int MovementType = 0;
    long long int HoverHeight = 0;
    double HealthModifier = 0;
    double ManaModifier = 0;
    double ArmorModifier = 0;
    long long int ExperienceModifier = 0;
    long long int RacialLeader = 0;
    long long int movementId = 0;
    long long int RegenHealth = 0;
    long long int mechanic_immune_mask = 0;
    long long int spell_school_immune_mask = 0;
    long long int flags_extra = 0;
    string ScriptName = "";
    long long int VerifiedBuild = 0;
vector<string> types = {"int","int","int","int","int","int","int","int","int","int","string","string","string","int","int","int","int","int","int","int","double","int","int","int","int","int","int","double","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","int","string","int","int","int","int","int","int","int","int","int","int","int","int","string","int"};
void ReadInValuesfromtxt(ifstream& Input) {
       string temp;
        getline(Input, temp, '(');
getline(Input, temp, '('); // skips to begining of values
        vector<string> values;
        int runs = 1;
        while (true) {
            if (runs == TotalNumValues) {
                getline(Input, temp);
                temp.pop_back();
                temp.pop_back();
                values.push_back(temp);
                break;
            }
            else {
                getline(Input, temp, ',');
            }
            string extension;
            if (temp != " NULL") {
                if (temp.size() > 2) {
                    while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                        temp += ',';
                        getline(Input, extension, ',');
                        temp += extension;
                        if (temp.size() > 1000000) {
                            entry = -1000;
                            return;
                        }
                    }
                    while (temp[temp.size() - 1] == '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] == char(92)) { // for commas in names
                        temp += ',';
                        getline(Input, extension, ',');
                        temp += extension;
                        if (temp.size() > 1000000) {
                            entry = -1000;
                            return;
                        }
                    }
                    while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                        temp += ',';
                        getline(Input, extension, ',');
                        temp += extension;
                        if (temp.size() > 1000000) {
                            entry = -1000;
                            return;
                        }
                    }
                    while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                        temp += ',';
                        getline(Input, extension, ',');
                        temp += extension;
                        if (temp.size() > 1000000) {
                            entry = -1000;
                            return;
                        }
                    }
                    while (temp[temp.size() - 1] == '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] == char(92)) { // for commas in names
                        temp += ',';
                        getline(Input, extension, ',');
                        temp += extension;
                        if (temp.size() > 1000000) {
                            entry = -1000;
                            return;
                        }
                    }
                    while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                        temp += ',';
                        getline(Input, extension, ',');
                        temp += extension;
                        if (temp.size() > 1000000) {
                            entry = -1000;
                            return;
                        }
                    }
                }
            }
            ++runs;
            values.push_back(temp);
        }
entry = stoll(values[0]);
difficulty_entry_1 = stoll(values[1]);
difficulty_entry_2 = stoll(values[2]);
difficulty_entry_3 = stoll(values[3]);
KillCredit1 = stoll(values[4]);
KillCredit2 = stoll(values[5]);
modelid1 = stoll(values[6]);
modelid2 = stoll(values[7]);
modelid3 = stoll(values[8]);
modelid4 = stoll(values[9]);
name =values[10];
subname =values[11];
IconName =values[12];
gossip_menu_id = stoll(values[13]);
minlevel = stoll(values[14]);
maxlevel = stoll(values[15]);
exp = stoll(values[16]);
faction = stoll(values[17]);
npcflag = stoll(values[18]);
speed_walk = stoll(values[19]);
speed_run = stod(values[20]);
speed_swim = stoll(values[21]);
speed_flight = stoll(values[22]);
detection_range = stoll(values[23]);
scale = stoll(values[24]);
rank = stoll(values[25]);
dmgschool = stoll(values[26]);
DamageModifier = stod(values[27]);
BaseAttackTime = stoll(values[28]);
RangeAttackTime = stoll(values[29]);
BaseVariance = stoll(values[30]);
RangeVariance = stoll(values[31]);
unit_class = stoll(values[32]);
unit_flags = stoll(values[33]);
unit_flags2 = stoll(values[34]);
dynamicflags = stoll(values[35]);
family = stoll(values[36]);
trainer_type = stoll(values[37]);
trainer_spell = stoll(values[38]);
trainer_class = stoll(values[39]);
trainer_race = stoll(values[40]);
type = stoll(values[41]);
type_flags = stoll(values[42]);
lootid = stoll(values[43]);
pickpocketloot = stoll(values[44]);
skinloot = stoll(values[45]);
PetSpellDataId = stoll(values[46]);
VehicleId = stoll(values[47]);
mingold = stoll(values[48]);
maxgold = stoll(values[49]);
AIName =values[50];
MovementType = stoll(values[51]);
HoverHeight = stoll(values[52]);
HealthModifier = stod(values[53]);
ManaModifier = stod(values[54]);
ArmorModifier = stod(values[55]);
ExperienceModifier = stoll(values[56]);
RacialLeader = stoll(values[57]);
movementId = stoll(values[58]);
RegenHealth = stoll(values[59]);
mechanic_immune_mask = stoll(values[60]);
spell_school_immune_mask = stoll(values[61]);
flags_extra = stoll(values[62]);
ScriptName =values[63];
VerifiedBuild = stoll(values[64]);
}
void ReadInValuesFromdotSQL(ifstream& Input) {
        string temp;
        vector<string> values;
        int runs = 1;
        while (true) {
            if (runs == TotalNumValues) {
                getline(Input, temp);
                temp.pop_back();
                temp.pop_back();
                values.push_back(temp);
                break;
            }
            else if (runs == 1) {
                getline(Input, temp, '(');
                stringstream ss;
                ss << temp;
                ss >> temp;
                if (temp == "REPLACE") {
                    entry = -1000;
                    return;
                }
                getline(Input, temp, ',');
            }
            else {
                getline(Input, temp, ',');
            }
            string extension;
            if (temp.size() > 2) {
                while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                    temp += ',';
                    getline(Input, extension, ',');
                    temp += extension;
                    if (temp.size() > 1000000) {
                        entry = -1000;
                        return;
                    }
                }
                while (temp[temp.size() - 1] == '\'' && types[runs - 1] == "string" && temp[temp.size()-2] == char(92)) { // for commas in names
                    temp += ',';
                    getline(Input, extension, ',');
                    temp += extension;
                    if (temp.size() > 1000000) {
                        entry = -1000;
                        return;
                    }
                }
                while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                    temp += ',';
                    getline(Input, extension, ',');
                    temp += extension;
                    if (temp.size() > 1000000) {
                        entry = -1000;
                        return;
                    }
                }
                while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                    temp += ',';
                    getline(Input, extension, ',');
                    temp += extension;
                    if (temp.size() > 1000000) {
                        entry = -1000;
                        return;
                    }
                }
                while (temp[temp.size() - 1] == '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] == char(92)) { // for commas in names
                    temp += ',';
                    getline(Input, extension, ',');
                    temp += extension;
                    if (temp.size() > 1000000) {
                        entry = -1000;
                        return;
                    }
                }
                while (temp[temp.size() - 1] != '\'' && types[runs - 1] == "string" && temp[temp.size() - 2] != char(92)) { // for commas in name
                    temp += ',';
                    getline(Input, extension, ',');
                    temp += extension;
                    if (temp.size() > 1000000) {
                        entry = -1000;
                        return;
                    }
                }
            }
            ++runs;
            values.push_back(temp);
        }
entry = stoll(values[0]);
difficulty_entry_1 = stoll(values[1]);
difficulty_entry_2 = stoll(values[2]);
difficulty_entry_3 = stoll(values[3]);
KillCredit1 = stoll(values[4]);
KillCredit2 = stoll(values[5]);
modelid1 = stoll(values[6]);
modelid2 = stoll(values[7]);
modelid3 = stoll(values[8]);
modelid4 = stoll(values[9]);
name =values[10];
subname =values[11];
IconName =values[12];
gossip_menu_id = stoll(values[13]);
minlevel = stoll(values[14]);
maxlevel = stoll(values[15]);
exp = stoll(values[16]);
faction = stoll(values[17]);
npcflag = stoll(values[18]);
speed_walk = stoll(values[19]);
speed_run = stod(values[20]);
speed_swim = stoll(values[21]);
speed_flight = stoll(values[22]);
detection_range = stoll(values[23]);
scale = stoll(values[24]);
rank = stoll(values[25]);
dmgschool = stoll(values[26]);
DamageModifier = stod(values[27]);
BaseAttackTime = stoll(values[28]);
RangeAttackTime = stoll(values[29]);
BaseVariance = stoll(values[30]);
RangeVariance = stoll(values[31]);
unit_class = stoll(values[32]);
unit_flags = stoll(values[33]);
unit_flags2 = stoll(values[34]);
dynamicflags = stoll(values[35]);
family = stoll(values[36]);
trainer_type = stoll(values[37]);
trainer_spell = stoll(values[38]);
trainer_class = stoll(values[39]);
trainer_race = stoll(values[40]);
type = stoll(values[41]);
type_flags = stoll(values[42]);
lootid = stoll(values[43]);
pickpocketloot = stoll(values[44]);
skinloot = stoll(values[45]);
PetSpellDataId = stoll(values[46]);
VehicleId = stoll(values[47]);
mingold = stoll(values[48]);
maxgold = stoll(values[49]);
AIName =values[50];
MovementType = stoll(values[51]);
HoverHeight = stoll(values[52]);
HealthModifier = stoll(values[53]);
ManaModifier = stoll(values[54]);
ArmorModifier = stoll(values[55]);
ExperienceModifier = stoll(values[56]);
RacialLeader = stoll(values[57]);
movementId = stoll(values[58]);
RegenHealth = stoll(values[59]);
mechanic_immune_mask = stoll(values[60]);
spell_school_immune_mask = stoll(values[61]);
flags_extra = stoll(values[62]);
ScriptName =values[63];
VerifiedBuild = stoll(values[64]);
}
string PreparedForOutput() {
        string output;
        output += "(";
output += to_string(entry);
output += ", ";
output += to_string(difficulty_entry_1);
output += ", ";
output += to_string(difficulty_entry_2);
output += ", ";
output += to_string(difficulty_entry_3);
output += ", ";
output += to_string(KillCredit1);
output += ", ";
output += to_string(KillCredit2);
output += ", ";
output += to_string(modelid1);
output += ", ";
output += to_string(modelid2);
output += ", ";
output += to_string(modelid3);
output += ", ";
output += to_string(modelid4);
output += ", ";
output += name;
output += ", ";
output += subname;
output += ", ";
output += IconName;
output += ", ";
output += to_string(gossip_menu_id);
output += ", ";
output += to_string(minlevel);
output += ", ";
output += to_string(maxlevel);
output += ", ";
output += to_string(exp);
output += ", ";
output += to_string(faction);
output += ", ";
output += to_string(npcflag);
output += ", ";
output += to_string(speed_walk);
output += ", ";
output += to_string(speed_run);
output += ", ";
output += to_string(speed_swim);
output += ", ";
output += to_string(speed_flight);
output += ", ";
output += to_string(detection_range);
output += ", ";
output += to_string(scale);
output += ", ";
output += to_string(rank);
output += ", ";
output += to_string(dmgschool);
output += ", ";
output += to_string(DamageModifier);
output += ", ";
output += to_string(BaseAttackTime);
output += ", ";
output += to_string(RangeAttackTime);
output += ", ";
output += to_string(BaseVariance);
output += ", ";
output += to_string(RangeVariance);
output += ", ";
output += to_string(unit_class);
output += ", ";
output += to_string(unit_flags);
output += ", ";
output += to_string(unit_flags2);
output += ", ";
output += to_string(dynamicflags);
output += ", ";
output += to_string(family);
output += ", ";
output += to_string(trainer_type);
output += ", ";
output += to_string(trainer_spell);
output += ", ";
output += to_string(trainer_class);
output += ", ";
output += to_string(trainer_race);
output += ", ";
output += to_string(type);
output += ", ";
output += to_string(type_flags);
output += ", ";
output += to_string(lootid);
output += ", ";
output += to_string(pickpocketloot);
output += ", ";
output += to_string(skinloot);
output += ", ";
output += to_string(PetSpellDataId);
output += ", ";
output += to_string(VehicleId);
output += ", ";
output += to_string(mingold);
output += ", ";
output += to_string(maxgold);
output += ", ";
output += AIName;
output += ", ";
output += to_string(MovementType);
output += ", ";
output += to_string(HoverHeight);
output += ", ";
output += to_string(HealthModifier);
output += ", ";
output += to_string(ManaModifier);
output += ", ";
output += to_string(ArmorModifier);
output += ", ";
output += to_string(ExperienceModifier);
output += ", ";
output += to_string(RacialLeader);
output += ", ";
output += to_string(movementId);
output += ", ";
output += to_string(RegenHealth);
output += ", ";
output += to_string(mechanic_immune_mask);
output += ", ";
output += to_string(spell_school_immune_mask);
output += ", ";
output += to_string(flags_extra);
output += ", ";
output += ScriptName;
output += ", ";
output += to_string(VerifiedBuild);
output += ")";
return output;
}
};