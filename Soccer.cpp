#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variables
int team_a_goals = 0, team_b_goals = 0; 
int team_a_shots_on_goal = 0, team_b_shots_on_goal = 0;
int team_a_shots_off_goal = 0, team_b_shots_off_goal = 0;
int team_a_blocked_shots = 0, team_b_blocked_shots = 0;
int team_a_fouls = 0, team_b_fouls = 0;
int team_a_yellow_cards = 0, team_b_yellow_cards = 0;
int team_a_red_cards = 0, team_b_red_cards = 0;


bool process_shot_result(int team) {
    int shot_outcome = rand() % 4;

    switch (shot_outcome) {
        case 0:
            cout << (team == 1 ? "Team A" : "Team B") << " scored a goal!\n";
            if (team == 1) {
                team_a_shots_on_goal++; // Increment shots on goal for Team A
            } else {
                team_b_shots_on_goal++; // Increment shots on goal for Team B
            }
            return true;
        case 1:
            cout << (team == 1 ? "Team A" : "Team B") << "'s shot was saved by the goalkeeper.\n";
            if (team == 1) {
                team_a_shots_on_goal++; // Increment shots on goal for Team A
            } else {
                team_b_shots_on_goal++; // Increment shots on goal for Team B
            }
            break;
        case 2:
            cout << (team == 1 ? "Team A" : "Team B") << "'s shot was off target.\n";
            if (team == 1) {
                team_a_shots_off_goal++; // Increment shots off goal for Team A
            } else {
                team_b_shots_off_goal++; // Increment shots off goal for Team B
            }
            break;
        case 3:
            cout << (team == 1 ? "Team A" : "Team B") << "'s shot was blocked by a defender.\n";
            if (team == 1) {
                team_a_blocked_shots++; // Increment blocked shots for Team A
            } else {
                team_b_blocked_shots++; // Increment blocked shots for Team B
            }
            break;
    }

    return false;
}


bool process_foul_result(int team, bool close_to_goal) {
    // Determine if a goal was scored
    if (close_to_goal) {
        return process_shot_result(team); // Treat penalty as a shot
    } else {
        int card = rand() % 3;
        if (card == 1) {
            cout << (team == 1 ? "Team B" : "Team A") << " received a yellow card.\n";
            if (team == 1) team_b_yellow_cards++; else team_a_yellow_cards++;
        } else if (card == 2) {
            cout << (team == 1 ? "Team B" : "Team A") << " received a red card!\n";
            if (team == 1) team_b_red_cards++; else team_a_red_cards++;
        } else {
            cout << (team == 1 ? "Team B" : "Team A") << " committed a foul with no card.\n";
        }
    }
    return false;
}

void simulate_event(int event_num) {
    int event_type = rand() % 6 + 1;

    switch (event_type) {
        case 1:
            cout << "Event " << event_num << ": Team A has a shot at target.\n";
            if (process_shot_result(1)) {
                team_a_goals++;
            }
            break;
        case 2:
            cout << "Event " << event_num << ": Team B has a shot at target.\n";
            if (process_shot_result(2)) {
                team_b_goals++;
            }
            break;
        case 3:
            cout << "Event " << event_num << ": Team B fouled Team A. Free kick awarded to Team A.\n";
            team_b_fouls++;
            process_foul_result(1, false);
            break;
        case 4:
            cout << "Event " << event_num << ": Team A fouled Team B. Free kick awarded to Team B.\n";
            team_a_fouls++;
            process_foul_result(2, false);
            break;
        case 5:
            cout << "Event " << event_num << ": Team B fouled close to the goal. Penalty for Team A.\n";
            team_b_fouls++;
            if (process_foul_result(1, true)) {
                team_a_goals++;
            }
            break;
        case 6:
            cout << "Event " << event_num << ": Team A fouled close to the goal. Penalty for Team B.\n";
            team_a_fouls++;
            if (process_foul_result(2, true)) {
                team_b_goals++;
            }
            break;
        default:
            cout << "Unknown event occurred.\n";
            break;
    }
}


void print_stats(int half) {
    cout << "\nEnd of Half " << half << " Stats:\n";
    cout << "Score: Team A " << team_a_goals << " - " << team_b_goals << " Team B\n";
    cout << "Team A - Shots on goal: " << team_a_shots_on_goal << ", Shots off goal: " << team_a_shots_off_goal << ", Blocked shots: " << team_a_blocked_shots << "\n";
    cout << "Team B - Shots on goal: " << team_b_shots_on_goal << ", Shots off goal: " << team_b_shots_off_goal << ", Blocked shots: " << team_b_blocked_shots << "\n";
    cout << "Fouls: Team A " << team_a_fouls << ", Team B " << team_b_fouls << "\n";
    cout << "Cards: Team A Yellow " << team_a_yellow_cards << ", Red " << team_a_red_cards << " - Team B Yellow " << team_b_yellow_cards << ", Red " << team_b_red_cards << "\n";
}

void start_soccer_simulation() {
    int total_events = rand() % 30 + 1;
    int events_in_half1 = total_events / 2;
    int events_in_half2 = total_events - events_in_half1;

    cout << "Starting the soccer game simulation!\n";
    cout << "Total number of events: " << total_events << "\n";

    // Simulate first half
    cout << "\n-- First Half --\n";
    for (int i = 0; i < events_in_half1; i++) {
        simulate_event(i + 1);
    }
    print_stats(1);

    // Simulate second half
    cout << "\n-- Second Half --\n";
    for (int i = 0; i < events_in_half2; i++) {
        simulate_event(i + 1);
    }
    print_stats(2);
}

//main 

int main() {
    srand(time(0));
    start_soccer_simulation();
    return 0;
}
