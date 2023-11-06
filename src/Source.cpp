#include <fstream>
#include <iostream>
#include <string>
#include <creature_template.h>
#include <random>
#include <sstream>

double HEALTHMAXNAMED = 2.0;
double HEALTHMINNAMED = 1.7;
double DAMAGEMAXNAMED = 2.0;
double DAMAGEMINNAMED = 1.5;
double HEALTHMAXUNNAMED = 1.35;
double HEALTHMINUNNAMED = 1.1;
double DAMAGEMAXUNNAMED = 1.25;
double DAMAGEMINUNNAMED = 1.0;

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
void ReadRanges(ifstream& is) {
	string line;
	stringstream ss;
	int valueIndex = 0;
	string buffer;
	while (getline(is, line)) {
		ss << line;
		ss >> buffer;
		ss >> buffer;
		ss >> buffer;
		buffer.pop_back();
		switch (valueIndex) {
		case 0: {
			HEALTHMAXNAMED = stod(buffer);
			break;
		}
		case 1: {
			HEALTHMINNAMED = stod(buffer);
			break;
		}
		case 2:{
			DAMAGEMAXNAMED = stod(buffer);
			break;
			}
		case 3: {
			DAMAGEMINNAMED = stod(buffer);
			break;
		}
		case 4: {
			HEALTHMAXUNNAMED = stod(buffer);
			break;
		}
		case 5: {
			HEALTHMINUNNAMED = stod(buffer);
			break;
		}
		case 6: {
			DAMAGEMAXUNNAMED = stod(buffer);
			break;
		}
		case 7: {
			DAMAGEMINUNNAMED = stod(buffer);
			break;
		}
		}
		buffer.erase();
		ss.clear();
		valueIndex++;
	}

}
int main() {
	srand(time(NULL));
	string modRangeNames = "ranges.txt";
	ifstream modRanges;
	modRanges.open(modRangeNames);
	if (!modRanges.is_open()) {
		cout << "Couldn't open " << modRangeNames;
		getchar();
		return 0;
	}
	ReadRanges(modRanges);
	ifstream inputFile;
	cout << "Creature_template modifier!\n";
	cout << "Don't forget no new line at the end of files or a baby penguin gets shot\n";
	cout << "1: Only named mobs\n";
	cout << "2: Only unnamed mobs\n";
	cout << "3: Both types\n";
	int mode = 0;
	string fname;
	vector<creature_template> output;
	if (cin >> mode) {
		if (mode > 3 || mode < 1) {
			cout << "terminating!\n";
			return 0;
		}
		switch (mode) {
		case 1: {
			fname = "named.txt";
			inputFile.open(fname);
			if (!inputFile.is_open()) {
				cout << "Couldn't open " << fname;
				getchar();
				return 0;
			}
			while (!inputFile.eof()) {
				creature_template temp = creature_template();
				temp.ReadInValuesfromtxt(inputFile);
				temp.DamageModifier = fRand(DAMAGEMINNAMED, DAMAGEMAXNAMED);
				temp.HealthModifier = fRand(HEALTHMINNAMED, HEALTHMAXNAMED);
				output.push_back(temp);
			}
			break;
		}
		case 2: {
			fname = "unnamed.txt";
			inputFile.open(fname);
			if (!inputFile.is_open()) {
				cout << "Couldn't open " << fname;
				getchar();
				return 0;
			}
			while (!inputFile.eof()) {
				creature_template temp = creature_template();
				temp.ReadInValuesfromtxt(inputFile);
				temp.DamageModifier = fRand(DAMAGEMINUNNAMED, DAMAGEMAXUNNAMED);
				temp.HealthModifier = fRand(HEALTHMINUNNAMED, HEALTHMAXUNNAMED);
				temp.rank = 0;
				output.push_back(temp);
			}
			break;
		}
		case 3: {
			fname = "named.txt";
			inputFile.open(fname);
			if (!inputFile.is_open()) {
				cout << "Couldn't open " << fname;
				getchar();
				return 0;
			}
			while (!inputFile.eof()) {
				creature_template temp = creature_template();
				temp.ReadInValuesfromtxt(inputFile);
				temp.DamageModifier = fRand(DAMAGEMINNAMED, DAMAGEMAXNAMED);
				temp.HealthModifier = fRand(HEALTHMINNAMED, HEALTHMAXNAMED);
				output.push_back(temp);
			}
			inputFile.close();
			fname = "unnamed.txt";
			inputFile.open(fname);
			if (!inputFile.is_open()) {
				cout << "Couldn't open " << fname;
				getchar();
				return 0;
			}
			while (!inputFile.eof()) {
				creature_template temp = creature_template();
				temp.ReadInValuesfromtxt(inputFile);
				temp.DamageModifier = fRand(DAMAGEMINUNNAMED, DAMAGEMAXUNNAMED);
				temp.HealthModifier = fRand(HEALTHMINUNNAMED, HEALTHMAXUNNAMED);
				temp.rank = 0;
				output.push_back(temp);
			}
			break;
		}
		}
	}
	fname = "unnamed.txt";
	inputFile.open(fname);
	if (!inputFile.is_open()) {
		cout << "Couldn't open " << fname;
		getchar();
		return 0;
	}
	string userInputName;
	string outputName = "zz_";
	cout << "Input an output file name \"zz_\" will be added to the front and \".sql\" will be added to the end automatically\n";
	cin >> userInputName;
	outputName += userInputName + ".sql";
	ofstream os(outputName);
	os << "REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `speed_swim`, `speed_flight`, `detection_range`, `scale`, `rank`, `dmgschool`, `DamageModifier`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES ";
	for (int i = 0; i < output.size(); i++) {
		os << output[i].PreparedForOutput();
		if (i != output.size() - 1) {
			os << ",\n";
		}
		else {
			os << ";";
		}
	}
	os.close();
	cout << "Job done!\n";
}