#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
void print_header();
void print_footer(double average);
void print_student(const std::string &student, int score);
int process_response(const std::string &response, const std::string &answer_key);

void print_header() {
    std::cout << std::setw(15) << std::left << "Student" 
                   << std::setw(5) << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');  
}

void print_footer(double average) {
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');  
    std::cout << std::setw(15) << std::left << "Average score"
                   << std::setw(5) << std::right << average;
}

void print_student(const std::string &student, int score) {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << student
                   << std::setw(5) << std::right << score << std::endl;
}

// return the number of correct responses
int process_response(const std::string &response, const std::string &answer_key) {
    int score {0};
    for (size_t i = 0; i < answer_key.size() ; ++i) {
        if (response.at(i)  == answer_key.at(i))
            score++;
    }
    return score;
}

int main() {
    std::ifstream in_file;
    std::string answer_key {};
    std::string name {};
    std::string response{};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};
    
in_file.open("./responses.txt");
     if (!in_file) {
        std::cerr << "❌ Problem opening file" << std::endl;
        return 1;
    }
    
    in_file >> answer_key;
    
    print_header();
    
    while (in_file >> name >> response) {
        ++total_students;
        int score = process_response(response, answer_key);
        running_sum += score;
        print_student(name, score);
    }

    if (total_students != 0)
        average_score = static_cast<double>(running_sum)/total_students;
        
    print_footer(average_score);
    
    in_file.close();
    std::cout << std::endl << std::endl;
    return 0;
}







/*void read_file(string responses.txt)

int main(){
    ifstream in_file {responses.txt};
    in_file.open("/Users/augustineaguworumba/Workspaces/Workspace1/AutomatedGrader");
    if(!in_file) {
        cerr << "❌ Problem opening file" << endl;
        return 1;
    } else {
        //cout << "✅ File opened successfully!" << endl;
        
        char c {};
        while(in_file.get(c)) {
            cout << c;
        }
        cout << endl;
        in_file.close();
        
        return 0;
    }
    }
     */ 

 
 
 
 
/* 
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::cout << "Current Working Directory: " << fs::current_path() << std::endl;
    
    std::ifstream in_file("/Users/augustineaguworumba/Workspaces/Workspace1/AutomatedGrader");  // Using just the file name

    if (!in_file) {
        std::cerr << "❌ Problem opening file" << std::endl;
        return 1;
    } else {
        std::cout << "✅ File opened successfully!" << std::endl;
    }

    in_file.close();
    return 0;
}
*/
