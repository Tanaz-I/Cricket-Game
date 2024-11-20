# Cricket Game

This is a simple cricket game simulation written in C. It allows users to play a cricket match between two teams, each consisting of 5 players. The game allows users to input runs, wickets, wides, and no-balls for each over, and generates match statistics including a scorecard, summary, and overall statistics.

## Features

- Two teams, each consisting of 5 players.
- 10 overs for each team.
- Runs scored, wickets taken, wides, and no-balls are tracked.
- Strike rates and economy rates for players are calculated.
- Match results and statistics (scorecard, summary, and overall stats) are displayed.

## Instructions

1. **Team Setup:**
   - Enter the names of players for both teams (5 players each).
   
2. **Game Simulation:**
   - The match is played in two innings. In the first inning, **Team 1** bats while **Team 2** bowls.
   - In the second inning, **Team 2** bats while **Team 1** bowls.
   
3. **Run Input:**
   - During each over, input the runs scored for each ball (choices: 0, 1, 2, 3, 4, 5, 6 for runs, 7 for a wide, 8 for a wicket, and 9 for a no-ball).
   - No-ball allows a free hit, and a wicket taken on a no-ball is not counted.
   
4. **Post-Match:**
   - After the match ends, you can choose to view the scorecard or player statistics.
   - The match winner is determined based on the team with the highest score after both innings.

## File Structure

- `TEAM_A.txt`: Contains match data for **Team 1**.
- `TEAM_B.txt`: Contains match data for **Team 2**.

## Usage

### Compiling the Game

To compile and run the game, use the following commands:

```bash
gcc -o cricket_game cricket_game.c
./cricket_game
