#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

class Mountain {
private:
    string name;
    string country;
    double elevation;

public:
    Mountain(const string& name, const string& country, double elevation)
        : name(name), country(country), elevation(elevation) {}

    // Getters
    string getName() const {
        return name;
    }

    string getCountry() const {
        return country;
    }

    double getElevation() const {
        return elevation;
    }

    // Setters
    void setName(const std::string& name) {
        this->name = name;
    }

    void setCountry(const string& country) {
        this->country = country;
    }

    void setElevation(double elevation) {
        this->elevation = elevation;
    }

    double toMeters() const {
        return elevation / 3.2808;
    }
};

class Main {
private:
    vector<Mountain> mountains;

public:
    void createMountainObjects() {
        mountains.emplace_back("Chimborazo", "Ecuador", 20549);
        mountains.emplace_back("Matterhorn", "Switzerland", 14692);
        mountains.emplace_back("Olympus", "Greece (Macedonia)", 9573);
        mountains.emplace_back("Everest", "Nepal", 29029);
        mountains.emplace_back("Mount Marcy - Adirondacks", "United States", 5344);
        mountains.emplace_back("Mount Mitchell - Blue Ridge", "United States", 6684);
        mountains.emplace_back("Zugspitze", "Switzerland", 9719);
    }

    double minElevation() const {
        if (mountains.empty()) {
            return 0.0; 
        }

        double minElev = mountains[0].getElevation();
        for (const auto& mountain : mountains) {
            if (mountain.getElevation() < minElev) {
                minElev = mountain.getElevation();
            }
        }

        return minElev;
    }



    void printMountainDetails() const {

      cout <<
    "┌────────────────────────────────┬───────────────────┬───────────────────────────┬─────────────────┐\n" 
    "│  Mountain                      │      Country      │         Elevation(f)      |   Elevation(m)  │\n"
    "├────────────────────────────────┼───────────────────┼───────────────────────────┼─────────────────┤\n"
      ;

        for (const auto& mountain : mountains) {
            cout << "|  " << mountain.getName() << setw(24)
                 << "|  " << setw(5) << mountain.getCountry() << setw(6)
                 << "|  " << setw(9) << mountain.getElevation() << "      | "<< mountain.toMeters() << "  |" << endl;
        }
    }

    void printShortestMountain() const {
        
        double minElev = minElevation();
        string shortestMountain;
        for (const auto& mountain : mountains) {
            if (mountain.getElevation() == minElev) {
                shortestMountain = mountain.getName();
                break;
            }
        }
        cout << endl;
        cout << "Shortest mountain: " << shortestMountain << " (Elevation: " << minElev << " ft)" << endl;
    }
};

int main() {
    Main mainObj;
    mainObj.createMountainObjects();

    mainObj.printMountainDetails();

    mainObj.printShortestMountain();


    return 0;
}


























/*#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Mountain {
private:
    string name;
    string country;
    double elevation;

public:
    Mountain(const string& name, const string& country, double elevation)
        : name(name), country(country), elevation(elevation) {}

    // Setters
    void setName(const string& name) {
        this->name = name;
    }

    void setCountry(const string& country) {
        this->country = country;
    }

    void setElevation(double elevation) {
        this->elevation = elevation;
    }

    // Getters
    std::string getName() const {
        return name;
    }

    std::string getCountry() const {
        return country;
    }

    double getElevation() const {
        return elevation;
    }

    double toMeters() const {
        return elevation / 3.2808;
    }
};

class Main {
public:
    static double minElevation(const vector<Mountain>& mountains) {
        if (mountains.empty()) {
            return 0.0;
        }

        double minElev = mountains[0].getElevation();
        for (const Mountain& mountain : mountains) {
            if (mountain.getElevation() < minElev) {
                minElev = mountain.getElevation();
            }
        }

        return minElev;
    }
};

int main() {
    vector<Mountain> mountains;

    mountains.emplace_back("Chimborazo", "Ecuador", 20549);
    mountains.emplace_back("Matterhorn", "Switzerland", 14692);
    mountains.emplace_back("Olympus", "Greece (Macedonia)", 9573);
    mountains.emplace_back("Everest", "Nepal", 29029);
    mountains.emplace_back("Mount Marcy - Adirondacks", "United States", 5344);
    mountains.emplace_back("Mount Mitchell - Blue Ridge", "United States", 6684);
    mountains.emplace_back("Zugspitze", "Switzerland", 9719);

    // Print Mountain details
    for (const Mountain& mountain : mountains) {
        cout << "Mountain: " << mountain.getName() << endl;
        cout << "Country: " << mountain.getCountry() << endl;
        cout << "Elevation (feet): " << mountain.getElevation() << endl;
        cout << "Elevation (meters): " << mountain.toMeters() << endl;
        cout << endl;
    }

    // Find minimum elevation
    double minElevation = Main::minElevation(mountains);
    cout << "Minimum Elevation: " << minElevation << " feet" << endl;

    // Find mountain with the minimum elevation
    for (const Mountain& mountain : mountains) {
        if (mountain.getElevation() == minElevation) {
            cout << "Shortest Mountain: " << mountain.getName() << endl;
            cout << "Elevation: " << mountain.getElevation() << " feet" << endl;
            break;
        }
    }

    return 0;
}
*/