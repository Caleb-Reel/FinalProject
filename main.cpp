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
            return 0.0; // Or some other appropriate value indicating no minimum
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
      
        cout << setfill('-') << setw(92) << "-" << endl;
    cout << setfill(' ');
    cout << left << "| " << setw(30) << "Mountain"
         << "| " << setw(25) << "Country"
         << "| " << setw(10) << "Elevation (ft)"
         << "| " << setw(18) << "Elevation (m) |" << endl;
    cout << setfill('-') << setw(92) << "-" << endl;
    cout << setfill(' ');

    for (const auto& mountain : mountains) {
        cout << left << "| " << setw(30) << mountain.getName()
             << "| " << setw(25) << mountain.getCountry()
             << "| " << setw(5) << setprecision(0) << fixed << mountain.getElevation() << " ft     "
             << " | " << setw(4) << setprecision(0) << fixed << mountain.toMeters() << " m        |" << endl;
    }

    cout << setfill('-') << setw(92) << "-" << endl;
    cout << setfill(' ');
}

   void printShortestMountain() const {
    double minElev = minElevation();
    string shortestMountain;
    double shortestMountainMeters = 0.0;

    for (const auto& mountain : mountains) {
        if (mountain.getElevation() == minElev) {
            shortestMountain = mountain.getName();
            shortestMountainMeters = mountain.toMeters();
            break;
        }
    }

    cout << "Shortest mountain: " << shortestMountain << " (Elevation: "
              << minElev << " ft / " << shortestMountainMeters << " m)" << endl;
}

};

int main() {
    Main mainObj;
    mainObj.createMountainObjects();

    mainObj.printMountainDetails();

    mainObj.printShortestMountain();


    return 0;
}



