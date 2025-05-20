#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include "PlayerX.h"
#include "PlayerO.h"
#include "PLAYER.h"
#include "COMPUTER.h"
using namespace std;
class GameManager {
public:
	GameManager() {
		srand(static_cast<unsigned int>(time(NULL)));
		playerturn = rand() % 2 == 0;
		quit = false;
		pozx = 10;
		pozo = 10;
		pozplayer = 10;
		computerPosition = 10;
		player1 = new PlayerX(pozx);
		player2 = new PlayerO(pozo);
		playervscomputer = new PLAYER(pozplayer);
		computer = new COMPUTER(computerPosition);
	}
	
	~GameManager(){
		delete  player1;
		player1 = nullptr;
		delete player2; player2 = nullptr;
		delete playervscomputer; playervscomputer = nullptr;
		delete computer; computer = nullptr;
	}

	void Draw() {
		system("cls");
		cout << endl;
		cout << "Game board:                                    " << "Available positions:" << endl << endl;

		cout << "    " << a[7] << " | " << a[8] << " | " << a[9];
		cout << "                                      ";

		if (indexarray[7] != 0)
			cout << indexarray[7];
		else
			cout << " ";
		cout << " | ";
		if (indexarray[8] != 0)
			cout << indexarray[8];
		else
			cout << " ";
		cout << " | ";
		if (indexarray[9] != 0)
			cout << indexarray[9];
		else
			cout << " ";
		cout << endl;
		cout << "   ";
		for(int aux = 1; aux <= 11; aux++)
			cout << ".";
		cout << "                                    ";
		for (int aux = 1; aux <= 11; aux++)
			cout << ".";
		cout << endl;
		



		cout << "    " << a[4] << " | " << a[5] << " | " << a[6];
		cout << "                                      ";
		if (indexarray[4] != 0)
			cout << indexarray[4];
		else
			cout << " ";
		cout << " | ";
		if (indexarray[5] != 0)
			cout << indexarray[5];
		else
			cout << " ";
		cout << " | ";
		if (indexarray[6] != 0)
			cout << indexarray[6];
		else
			cout << " ";
		cout << endl;
		cout << "   ";
		for (int aux = 1; aux <= 11; aux++)
			cout << ".";
		cout << "                                    ";
		for (int aux = 1; aux <= 11; aux++)
			cout << ".";
		cout << endl;


		cout << "    " << a[1] << " | " << a[2] << " | " << a[3]; 
		cout << "                                      ";
		if (indexarray[1] != 0)
			cout << indexarray[1];
		else
			cout << " ";
		cout << " | ";
		if (indexarray[2] != 0)
			cout << indexarray[2];
		else
			cout << " ";
		cout << " | ";
		if (indexarray[3] != 0)
			cout << indexarray[3];
		else
			cout << " ";
		
	};

	void StartMessage() {
		cout << "               TICTACTOE GAME " << endl << endl << endl << endl << endl;
		cout << "Type \"pvp\" if you want to play player vs player" << endl;
		cout << "Type \"pvc\" if you want to play player vs computer" << endl;
		cout << "The game type :";
		cin >> messagechoose;
		if (messagechoose == "pvp") {
			system("cls");
			StartMessagePVPlayer();
		}
		else
			if (messagechoose == "pvc") {
				system("cls");
				StartMessagePVComputer();
			}
			else
				if (messagechoose != "pvp" || messagechoose != "pvc") {

				}
	}
	void StartMessagePVPlayer() {
		cout << "               TICTACTOE GAME " << endl << endl << endl;
		cout << "Rules and conditions:" << endl<<endl;
		cout << "1: The numbers from the numeric keypad are used as controls for positioning. " << endl;
		cout << "Example: if you press 7 and then ENTER, the character will be placed in the top left corner;" << endl<<endl;
		cout << "2: The game begins when the first player places a character, the first character always being a \"x\"."<<endl<<endl;
		cout << "3: The players will take turns in placing their designated characters until one of them wins, or until they reach a tie, this being displayed as \"DRAW!\";" <<endl<< endl;
		cout<< "If you understand, please type \"YES\" so that you can play and then press ENTER: ";
		cin >> messageyes;	
    }
	void StartMessagePVComputer() {
		cout << "               TICTACTOE GAME " << endl << endl << endl;
		cout << "Rules and conditions:" << endl << endl;
		cout << "1: The numbers from the numeric keypad are used as controls for positioning. " << endl;
		cout << "Example: if you press 7 and then ENTER, the character will be placed in the top left corner;" << endl << endl;
		cout << "2: You will choose the character you prefer between \"x\" and \"o\";" << endl << endl;
		cout << "3: You and the computer will take turns in placing your designated characters until one of you wins, or until you reach a tie, this being displayed as \"DRAW!\";" << endl << endl;
		cout << "Choose the difficulty between: easy, medium, impossible: ";
		cin >> difficulty;
	}


	int checkfirstmove() {
		int ok = 1;
		for (int i = 1; i <= 9; i++)
			if (indexarray[i] == 0)
				ok = 0;
		return ok;
	}


	// player vs computer


	void Inputpvcomputereasy() {
		if (!quit) {
			if (playerturn == 0) {
					random_device rd;
					mt19937 generator(rd());
					uniform_int_distribution<> distribution(1, 9);
					do {
						computerPosition = distribution(generator);
					} while (indexarray[computerPosition ] == 0);
					a[computerPosition] = computer->GetSymbol();
					indexarray[computerPosition ] = 0;
					playerturn = 1;
			}
			else if (playerturn == 1) {
					cout << endl << endl;
					cout << "Choose a position :";
					playervscomputer->setpoz();
					pozplayer = playervscomputer->getpoz();
			
					if (indexarray[pozplayer ] != 0) {
						Draw();
						a[pozplayer] = playervscomputer->getsymbol();
						indexarray[pozplayer ] = 0;
						Draw();
					}
					else
					{
						do
						{
							cout << "An available position please:";
							playervscomputer->setpoz();
							pozplayer = playervscomputer->getpoz();
						} while (indexarray[pozplayer ] == 0);
						a[pozplayer] = playervscomputer->getsymbol();
						indexarray[pozplayer ] = 0;
						Draw();
					}
					playerturn = 0;
				}
		}
	}
	//done


	void Inputpvcomputermedium() {
		if (!quit) {
			if (playerturn == 0) {
				if (checkfirstmove() == 1) {
					random_device rd;
					mt19937 generator(rd());
					uniform_int_distribution<> distribution(1, 9);
					do {
						computerPosition = distribution(generator);
					} while (indexarray[computerPosition] == 0);
					a[computerPosition] = computer->GetSymbol();
					indexarray[computerPosition ] = 0;
				}
				else
					if (checkfirstmove() == 0)
					{
						int placed = 0;
						//check for winning
						if (placed == 0) {
							if (a[7] == a[8] && a[7] != " " && a[9] == " ") {
								a[9] = computer->GetSymbol();
								indexarray[9] = 0;
								placed = 1;
							}
							else if (a[7] == a[9] && a[7] != " " && a[8] == " ") {
								a[8] = computer->GetSymbol();
								indexarray[8] = 0;
								placed = 1;
							}
							else if (a[8] == a[9] && a[8] != " " && a[7] == " ") {
								a[7] = computer->GetSymbol();
								indexarray[7] = 0;
								placed = 1;
							}
						}
						if (placed == 0) {
							if (a[4] == a[5] && a[4] != " " && a[6] == " ") {
								a[6] = computer->GetSymbol();
								indexarray[6] = 0;
								placed = 1;
							}
							else if (a[4] == a[6] && a[4] != " " && a[5] == " ") {
								a[5] = computer->GetSymbol();
								indexarray[5] = 0;
								placed = 1;
							}
							else if (a[5] == a[6] && a[5] != " " && a[4] == " ") {
								a[4] = computer->GetSymbol();
								indexarray[4] = 0;
								placed = 1;
							}
						}
						if (placed == 0) {
							if (a[1] == a[2] && a[1] != " " && a[3] == " ") {
								a[3] = computer->GetSymbol();
								indexarray[3] = 0; placed = 1;
							}
							else if (a[1] == a[3] && a[1] != " " && a[2] == " ") {
								a[2] = computer->GetSymbol();
								indexarray[2] = 0; placed = 1;
							}
							else if (a[2] == a[3] && a[2] != " " && a[1] == " ") {
								a[1] = computer->GetSymbol();
								indexarray[1] = 0; placed = 1;
							}
						}
						
						if (placed == 0) {
							if (a[1] == a[4] && a[1] != " " && a[7] == " ") {
								a[7] = computer->GetSymbol();
								indexarray[7] = 0; placed = 1;
							}
							else if (a[1] == a[7] && a[1] != " " && a[4] == " ") {
								a[4] = computer->GetSymbol();
								indexarray[4] = 0; placed = 1;
							}
							else if (a[4] == a[7] && a[4] != " " && a[1] == " ") {
								a[1] = computer->GetSymbol();
								indexarray[1] = 0; placed = 1;
							}
						}
						if (placed == 0) {
							if (a[2] == a[5] && a[2] != " " && a[8] == " ") {
								a[8] = computer->GetSymbol();
								indexarray[8] = 0; placed = 1;
							}
							else if (a[2] == a[8] && a[2] != " " && a[5] == " ") {
								a[5] = computer->GetSymbol();
								indexarray[5] = 0; placed = 1;
							}
							else if (a[5] == a[8] && a[5] != " " && a[2] == " ") {
								a[2] = computer->GetSymbol();
								indexarray[2] = 0; placed = 1;
							}
						}
						if (placed == 0) {
							if (a[3] == a[6] && a[3] != " " && a[9] == " ") {
								a[9] = computer->GetSymbol();
								indexarray[9] = 0; placed = 1;
							}
							else if (a[3] == a[9] && a[3] != " " && a[6] == " ") {
								a[6] = computer->GetSymbol();
								indexarray[6] = 0; placed = 1;
							}
							else if (a[6] == a[9] && a[6] != " " && a[3] == " ") {
								a[3] = computer->GetSymbol();
								indexarray[3] = 0; placed = 1;
							}
						}
						
						if (placed == 0) {
							if (a[3] == a[5] && a[3] != " " && a[7] == " ") {
								a[7] = computer->GetSymbol();
								indexarray[7] = 0; placed = 1;
							}
							else if (a[3] == a[7] && a[3] != " " && a[5] == " ") {
								a[5] = computer->GetSymbol();
								indexarray[5] = 0; placed = 1;
							}
							else if (a[5] == a[7] && a[5] != " " && a[3] == " ") {
								a[3] = computer->GetSymbol();
								indexarray[3] = 0; placed = 1; 
							}
						}
						if (placed == 0) {
							if (a[1] == a[5] && a[1] != " " && a[9] == " ") {
								a[9] = computer->GetSymbol();
								indexarray[9] = 0; placed = 1; 
							}
							else if (a[1] == a[9] && a[1] != " " && a[5] == " ") {
								a[5] = computer->GetSymbol();
								indexarray[5] = 0; placed = 1; 
							}
							else if (a[5] == a[9] && a[5] != " " && a[1] == " ") {
								a[1] = computer->GetSymbol();
								indexarray[1] = 0; placed = 1; 
							}

						}
						
						
						if (placed == 0) {
							int numberofoddindexes=0;
							for (int i = 1; i <= 9; i = i + 2) {
								if (indexarray[i] != 0)
									numberofoddindexes++;
							}
							if (numberofoddindexes != 0) {
								int randomoddposition;

								do {
									randomoddposition = rand() % 5 * 2 + 1; 
								} while (indexarray[randomoddposition ] == 0);
								indexarray[randomoddposition] = 0;
								a[randomoddposition] = computer->GetSymbol();
								placed = 1;
							}
							else
								if (numberofoddindexes == 0) {
									int randomevenposition;

									do {
										randomevenposition = rand() % 5 * 2 + 2; // Generate a random even index (excluding 0)
									} while (indexarray[randomevenposition] == 0);
									indexarray[randomevenposition] = 0;
									a[randomevenposition] = computer->GetSymbol();
									placed = 1;
								}
						}

					}
				playerturn = 1;

			}
			else if (playerturn == 1) {
				cout << endl << endl;
				cout << "Choose a position :";
				playervscomputer->setpoz();
				pozplayer = playervscomputer->getpoz();

				if (indexarray[pozplayer ] != 0) {
					Draw();
					a[pozplayer] = playervscomputer->getsymbol();
					indexarray[pozplayer ] = 0;
					Draw();
				}
				else
				{
					do
					{
						cout << "An available position please:";
						playervscomputer->setpoz();
						pozplayer = playervscomputer->getpoz();
					} while (indexarray[pozplayer ] == 0);
					a[pozplayer] = playervscomputer->getsymbol();
					indexarray[pozplayer ] = 0;

					Draw();
				}
				playerturn = 0;
			}
		}
	}
	//done


	
	void Inputpvcomputerimpossible() {
		int firstmovevalue;
		bool firstmove = checkfirstmove();
		if (playerturn == 1)
			firstmovevalue = 0;
	
		if (!quit) {
			if (playerturn == 0) {
				if (checkfirstmove() == 1) {
					//places in a random corner since all of them are empty
					int randomcornerposition = rand() % 5 * 2 + 1;
					if (randomcornerposition != 5) {
						computerPosition = randomcornerposition;
						a[computerPosition] = computer->GetSymbol();
						indexarray[computerPosition] = 0;
					}
					else {
						do {
							randomcornerposition = rand() % 5 * 2 + 1;
						} while (randomcornerposition == 5);
						computerPosition = randomcornerposition;
						a[computerPosition] = computer->GetSymbol();
						indexarray[computerPosition] = 0;
					}
					firstmovevalue = computerPosition;
				}
				else
					if (checkfirstmove() == 0)
					{
						int placed = 0;
						int randcornerpos = rand() % 5 * 2 + 1;
						int randomsides = rand() % 5 * 2;
						int number_of_placed_symbols=0;

						//if the computer got first move
						if (firstmove == 1) {

							
							//checks for a winning move instantly
							if (placed == 0) {
								if (a[7] == a[8] && a[7] != " " && a[9] == " ") {
									a[9] = computer->GetSymbol();
									indexarray[9] = 0;
									placed = 1;
								}
								else if (a[7] == a[9] && a[7] != " " && a[8] == " ") {
									a[8] = computer->GetSymbol();
									indexarray[8] = 0;
									placed = 1;
								}
								else if (a[8] == a[9] && a[8] != " " && a[7] == " ") {
									a[7] = computer->GetSymbol();
									indexarray[7] = 0;
									placed = 1;
								}
							}
							if (placed == 0) {
								if (a[4] == a[5] && a[4] != " " && a[6] == " ") {
									a[6] = computer->GetSymbol();
									indexarray[6] = 0;
									placed = 1;
								}
								else if (a[4] == a[6] && a[4] != " " && a[5] == " ") {
									a[5] = computer->GetSymbol();
									indexarray[5] = 0;
									placed = 1;
								}
								else if (a[5] == a[6] && a[5] != " " && a[4] == " ") {
									a[4] = computer->GetSymbol();
									indexarray[4] = 0;
									placed = 1;
								}
							}
							if (placed == 0) {
								if (a[1] == a[2] && a[1] != " " && a[3] == " ") {
									a[3] = computer->GetSymbol();
									indexarray[3] = 0; placed = 1;
								}
								else if (a[1] == a[3] && a[1] != " " && a[2] == " ") {
									a[2] = computer->GetSymbol();
									indexarray[2] = 0; placed = 1;
								}
								else if (a[2] == a[3] && a[2] != " " && a[1] == " ") {
									a[1] = computer->GetSymbol();
									indexarray[1] = 0; placed = 1;
								}
							}

							if (placed == 0) {
								if (a[1] == a[4] && a[1] != " " && a[7] == " ") {
									a[7] = computer->GetSymbol();
									indexarray[7] = 0; placed = 1;
								}
								else if (a[1] == a[7] && a[1] != " " && a[4] == " ") {
									a[4] = computer->GetSymbol();
									indexarray[4] = 0; placed = 1;
								}
								else if (a[4] == a[7] && a[4] != " " && a[1] == " ") {
									a[1] = computer->GetSymbol();
									indexarray[1] = 0; placed = 1;
								}
							}
							if (placed == 0) {
								if (a[2] == a[5] && a[2] != " " && a[8] == " ") {
									a[8] = computer->GetSymbol();
									indexarray[8] = 0; placed = 1;
								}
								else if (a[2] == a[8] && a[2] != " " && a[5] == " ") {
									a[5] = computer->GetSymbol();
									indexarray[5] = 0; placed = 1;
								}
								else if (a[5] == a[8] && a[5] != " " && a[2] == " ") {
									a[2] = computer->GetSymbol();
									indexarray[2] = 0; placed = 1;
								}
							}
							if (placed == 0) {
								if (a[3] == a[6] && a[3] != " " && a[9] == " ") {
									a[9] = computer->GetSymbol();
									indexarray[9] = 0; placed = 1;
								}
								else if (a[3] == a[9] && a[3] != " " && a[6] == " ") {
									a[6] = computer->GetSymbol();
									indexarray[6] = 0; placed = 1;
								}
								else if (a[6] == a[9] && a[6] != " " && a[3] == " ") {
									a[3] = computer->GetSymbol();
									indexarray[3] = 0; placed = 1;
								}
							}

							if (placed == 0) {
								if (a[3] == a[5] && a[3] != " " && a[7] == " ") {
									a[7] = computer->GetSymbol();
									indexarray[7] = 0; placed = 1;
								}
								else if (a[3] == a[7] && a[3] != " " && a[5] == " ") {
									a[5] = computer->GetSymbol();
									indexarray[5] = 0; placed = 1;
								}
								else if (a[5] == a[7] && a[5] != " " && a[3] == " ") {
									a[3] = computer->GetSymbol();
									indexarray[3] = 0; placed = 1;
								}
							}
							if (placed == 0) {
								if (a[1] == a[5] && a[1] != " " && a[9] == " ") {
									a[9] = computer->GetSymbol();
									indexarray[9] = 0; placed = 1;
								}
								else if (a[1] == a[9] && a[1] != " " && a[5] == " ") {
									a[5] = computer->GetSymbol();
									indexarray[5] = 0; placed = 1;
								}
								else if (a[5] == a[9] && a[5] != " " && a[1] == " ") {
									a[1] = computer->GetSymbol();
									indexarray[1] = 0; placed = 1;
								}

							}

							for (int i = 1; i <= 9; i++)
								if (a[i] != " ")
									number_of_placed_symbols++;
							
							if (number_of_placed_symbols == 2) {
								if (a[5] == playervscomputer->getsymbol()) {
									if (a[1] == computer->GetSymbol() && placed == 0) {
										a[9] = computer->GetSymbol();
										indexarray[9] = 0;
										placed = 1;
									}
									if (a[3] == computer->GetSymbol() && placed == 0) {
										a[7] = computer->GetSymbol();
										indexarray[7] = 0;
										placed = 1;
									}
									if (a[7] == computer->GetSymbol() && placed == 0) {
										a[3] = computer->GetSymbol();
										indexarray[3] = 0;
										placed = 1;
									}
									if (a[9] == computer->GetSymbol() && placed == 0) {
										a[1] = computer->GetSymbol();
										indexarray[1] = 0;
										placed = 1;
									}

								}
								else
								{
									if (a[1] == computer->GetSymbol()) {
										if (a[2] == playervscomputer->getsymbol()&&placed==0) {
											a[7] = computer->GetSymbol();
											indexarray[7] = 0;
											placed = 1;
										}
										if (a[4] == playervscomputer->getsymbol() && placed == 0) {
												a[3] = computer->GetSymbol();
												indexarray[3] = 0;
												placed = 1;
											}
										if (a[7] == " " && placed == 0) {
											a[7] = computer->GetSymbol();
											indexarray[7] = 0;
											placed = 1;
										}
										if (a[3] == " " && placed == 0) {
											a[3] = computer->GetSymbol();
											indexarray[3] = 0;
											placed = 1;
										}
									}
									if (a[3] == computer->GetSymbol() ) {
										if (a[2] == playervscomputer->getsymbol() && placed == 0) {
											a[9] = computer->GetSymbol();
											indexarray[9] = 0;
											placed = 1;
										}
										if (a[6] == playervscomputer->getsymbol() && placed == 0) {
												a[1] = computer->GetSymbol();
												indexarray[1] = 0;
												placed = 1;
											}
										if (a[1] == " " && placed == 0) {
											a[1] = computer->GetSymbol();
											indexarray[1] = 0;
											placed = 1;
										}
										if (a[9] == " " && placed == 0) {
											a[9] = computer->GetSymbol();
											indexarray[9] = 0;
											placed = 1;
										}

									}
									if (a[7] == computer->GetSymbol() ) {
										if (a[8] == playervscomputer->getsymbol() && placed == 0) {
											a[1] = computer->GetSymbol();
											indexarray[1] = 0;
											placed = 1;
										}
										if (a[4] == playervscomputer->getsymbol() && placed == 0) {
												a[9] = computer->GetSymbol();
												indexarray[9] = 0;
												placed = 1;
											}
										if (a[1] == " " && placed == 0) {
											a[1] = computer->GetSymbol();
											indexarray[1] = 0;
											placed = 1;
										}
										if (a[9] == " " && placed == 0) {
											a[9] = computer->GetSymbol();
											indexarray[9] = 0;
											placed = 1;
										}

									}
									if (a[9] == computer->GetSymbol()) {
										if (a[8] == playervscomputer->getsymbol() && placed == 0) {
											a[3] = computer->GetSymbol();
											indexarray[3] = 0;
											placed = 1;
										}
										if (a[6] == playervscomputer->getsymbol() && placed == 0) {
												a[7] = computer->GetSymbol();
												indexarray[7] = 0;
												placed = 1;
											}
										if (a[7] == " " && placed == 0) {
											a[7] = computer->GetSymbol();
											indexarray[7] = 0;
											placed = 1;
										}
										if (a[3] == " " && placed == 0) {
											a[3] = computer->GetSymbol(); 
											indexarray[3] = 0; 
											placed = 1; 
										}
									}
								}
							}

		

							if (number_of_placed_symbols == 4) {
									if (a[1] == computer->GetSymbol() && firstmovevalue == 1) {
										if (a[3] == computer->GetSymbol()) {
											a[9] = computer->GetSymbol();
											indexarray[9] = 0;
											placed = 1;
										}
										if (a[7] == computer->GetSymbol()) {
											a[9] = computer->GetSymbol();
											indexarray[9] = 0;
											placed = 1;
										}
									}
									if (a[3] == computer->GetSymbol() && firstmovevalue == 3) {
										if (a[1] == computer->GetSymbol()) {
											a[7] = computer->GetSymbol();
											indexarray[7] = 0;
											placed = 1;
										}
										if (a[9] == computer->GetSymbol()) {
											a[7] = computer->GetSymbol();
											indexarray[7] = 0;
											placed = 1;
										}
									}
									if (a[7] == computer->GetSymbol() && firstmovevalue == 7) {
										if (a[1] == computer->GetSymbol()) {
											a[3] = computer->GetSymbol();
											indexarray[3] = 0;
											placed = 1;
										}
										if (a[9] == computer->GetSymbol()) {
											a[3] = computer->GetSymbol();
											indexarray[3] = 0;
											placed = 1;
										}
									}
									if (a[9] == computer->GetSymbol() && firstmovevalue == 9) {
										if (a[3] == computer->GetSymbol()) {
											a[1] = computer->GetSymbol();
											indexarray[1] = 0;
											placed = 1;
										}
										if (a[7] == computer->GetSymbol()) {
											a[1] = computer->GetSymbol();
											indexarray[1] = 0;
											placed = 1;
										}
									}
								}
							

							//places in another corner
							if (placed == 0) {
									if (a[randcornerpos] == " ") {
										computerPosition = randcornerpos;
										a[computerPosition] = computer->GetSymbol();
										indexarray[computerPosition] = 0;
										placed = 1;
									}
									else
										if (a[randcornerpos] != " ") {
											do {
												randcornerpos = rand() % 5 * 2 + 1;
											} while (a[randcornerpos] != " ");
											computerPosition = randcornerpos;
											a[computerPosition] = computer->GetSymbol();
											indexarray[computerPosition] = 0;
											placed = 1;
										}
							}



							//places in another side if needed;
							if (randomsides == 0|| a[randomsides]!=" "){
								do {
									randomsides = rand() % 2 * 2;
								} while (randomsides == 0 || a[randomsides] != " ");
							}
							if (placed == 0) {
								computerPosition = randomsides;
								a[computerPosition] = computer->GetSymbol();
								indexarray[computerPosition] = 0;
								placed = 1;
							}



						}
						//if the computer got second move
						else
							if (firstmove == 0) {
								int placed = 0;
								int number_of_placed_symbols = 0;
								int randomcornerpos = rand() % 5 * 2 + 1;
								int randomsides=rand()%2*2;

								//checks for a winning move instantly
								if (placed == 0) {
									if (a[7] == a[8] && a[7] != " " && a[9] == " ") {
										a[9] = computer->GetSymbol();
										indexarray[9] = 0;
										placed = 1;
									}
									else if (a[7] == a[9] && a[7] != " " && a[8] == " ") {
										a[8] = computer->GetSymbol();
										indexarray[8] = 0;
										placed = 1;
									}
									else if (a[8] == a[9] && a[8] != " " && a[7] == " ") {
										a[7] = computer->GetSymbol();
										indexarray[7] = 0;
										placed = 1;
									}
								}
								if (placed == 0) {
									if (a[4] == a[5] && a[4] != " " && a[6] == " ") {
										a[6] = computer->GetSymbol();
										indexarray[6] = 0;
										placed = 1;
									}
									else if (a[4] == a[6] && a[4] != " " && a[5] == " ") {
										a[5] = computer->GetSymbol();
										indexarray[5] = 0;
										placed = 1;
									}
									else if (a[5] == a[6] && a[5] != " " && a[4] == " ") {
										a[4] = computer->GetSymbol();
										indexarray[4] = 0;
										placed = 1;
									}
								}
								if (placed == 0) {
									if (a[1] == a[2] && a[1] != " " && a[3] == " ") {
										a[3] = computer->GetSymbol();
										indexarray[3] = 0; placed = 1;
									}
									else if (a[1] == a[3] && a[1] != " " && a[2] == " ") {
										a[2] = computer->GetSymbol();
										indexarray[2] = 0; placed = 1;
									}
									else if (a[2] == a[3] && a[2] != " " && a[1] == " ") {
										a[1] = computer->GetSymbol();
										indexarray[1] = 0; placed = 1;
									}
								}

								if (placed == 0) {
									if (a[1] == a[4] && a[1] != " " && a[7] == " ") {
										a[7] = computer->GetSymbol();
										indexarray[7] = 0; placed = 1;
									}
									else if (a[1] == a[7] && a[1] != " " && a[4] == " ") {
										a[4] = computer->GetSymbol();
										indexarray[4] = 0; placed = 1;
									}
									else if (a[4] == a[7] && a[4] != " " && a[1] == " ") {
										a[1] = computer->GetSymbol();
										indexarray[1] = 0; placed = 1;
									}
								}
								if (placed == 0) {
									if (a[2] == a[5] && a[2] != " " && a[8] == " ") {
										a[8] = computer->GetSymbol();
										indexarray[8] = 0; placed = 1;
									}
									else if (a[2] == a[8] && a[2] != " " && a[5] == " ") {
										a[5] = computer->GetSymbol();
										indexarray[5] = 0; placed = 1;
									}
									else if (a[5] == a[8] && a[5] != " " && a[2] == " ") {
										a[2] = computer->GetSymbol();
										indexarray[2] = 0; placed = 1;
									}
								}
								if (placed == 0) {
									if (a[3] == a[6] && a[3] != " " && a[9] == " ") {
										a[9] = computer->GetSymbol();
										indexarray[9] = 0; placed = 1;
									}
									else if (a[3] == a[9] && a[3] != " " && a[6] == " ") {
										a[6] = computer->GetSymbol();
										indexarray[6] = 0; placed = 1;
									}
									else if (a[6] == a[9] && a[6] != " " && a[3] == " ") {
										a[3] = computer->GetSymbol();
										indexarray[3] = 0; placed = 1;
									}
								}

								if (placed == 0) {
									if (a[3] == a[5] && a[3] != " " && a[7] == " ") {
										a[7] = computer->GetSymbol();
										indexarray[7] = 0; placed = 1;
									}
									else if (a[3] == a[7] && a[3] != " " && a[5] == " ") {
										a[5] = computer->GetSymbol();
										indexarray[5] = 0; placed = 1;
									}
									else if (a[5] == a[7] && a[5] != " " && a[3] == " ") {
										a[3] = computer->GetSymbol();
										indexarray[3] = 0; placed = 1;
									}
								}
								if (placed == 0) {
									if (a[1] == a[5] && a[1] != " " && a[9] == " ") {
										a[9] = computer->GetSymbol();
										indexarray[9] = 0; placed = 1;
									}
									else if (a[1] == a[9] && a[1] != " " && a[5] == " ") {
										a[5] = computer->GetSymbol();
										indexarray[5] = 0; placed = 1;
									}
									else if (a[5] == a[9] && a[5] != " " && a[1] == " ") {
										a[1] = computer->GetSymbol();
										indexarray[1] = 0; placed = 1;
									}

								}

								for (int i = 1; i <= 9; i++)
									if (a[i] != " ")
										number_of_placed_symbols++;

								if (number_of_placed_symbols == 1) {
									if (a[5] == " ") {
										a[5] = computer->GetSymbol();
										indexarray[5] = 0;
										placed = 1;
									}
									else 
										if (placed == 0) {
											if (a[randcornerpos] == " ") {
												computerPosition = randcornerpos;
												a[computerPosition] = computer->GetSymbol();
												indexarray[computerPosition] = 0;
												placed = 1;
											}
											else
												if (a[randcornerpos] != " ") {
													do {
														randcornerpos = rand() % 5 * 2 + 1;
													} while (a[randcornerpos] != " ");
													computerPosition = randcornerpos;
													a[computerPosition] = computer->GetSymbol();
													indexarray[computerPosition] = 0;
													placed = 1;
												}
										}
									
								}




								if (number_of_placed_symbols == 3) {
									if (a[1] == playervscomputer->getsymbol() && a[9] == playervscomputer->getsymbol() && placed==0)  {
										if (randomsides == 0 || a[randomsides] != " ") {
											do {
												randomsides = rand() % 2 * 2;
											} while (randomsides == 0 || a[randomsides] != " ");
										}
										computerPosition = randomsides;
										a[computerPosition] = computer->GetSymbol();
										indexarray[computerPosition] = 0;
										placed = 1;
									}
									if (a[3] == playervscomputer->getsymbol() && a[7] == playervscomputer->getsymbol() && placed == 0) {
										if (randomsides == 0 || a[randomsides] != " ") {
											do {
												randomsides = rand() % 2 * 2;
											} while (randomsides == 0 || a[randomsides] != " ");
										}
										computerPosition = randomsides;
										a[computerPosition] = computer->GetSymbol();
										indexarray[computerPosition] = 0;
										placed = 1;
									}
								}

								int emptyspace = 0;
								for (int i = 1; i <= 9; i++) {
									if (indexarray[i] != 0)
									{
										emptyspace = i;
										break;
									}
								}
								if (placed == 0) {
									a[emptyspace] = computer->GetSymbol();
									indexarray[emptyspace] = 0;
								}


							}
					}
					//the computer's turn is over
					playerturn = 1;
			}
			else 
				if (playerturn == 1) {
				cout << endl << endl;
				cout << "Choose a position :";
				playervscomputer->setpoz();
				pozplayer = playervscomputer->getpoz();

				if (indexarray[pozplayer] != 0) {
					Draw();
					a[pozplayer] = playervscomputer->getsymbol();
					indexarray[pozplayer] = 0;
					Draw();
				}
				else
				{
					do
					{
						cout << "An available position please:";
						playervscomputer->setpoz();
						pozplayer = playervscomputer->getpoz();
					} while (indexarray[pozplayer] == 0);
					a[pozplayer] = playervscomputer->getsymbol();
					indexarray[pozplayer] = 0;
					Draw();
				}
				playerturn = 0;
			}


		}
	}
	


	void Logicpvcomputer() {
	

			int emptyCount = 0;
			for (int i = 1; i <= 9; i++) {
				if (a[i] == " ") {
					emptyCount++;
				}
			}

			if (a[7] == a[8] && a[8] == a[9] && a[9] != " ")
				if (a[7] == "x") {
					winner = 1;
					quit = true;
				}
				else
					if (a[7] == "o")
					{
						winner = 2;
						quit = true;
					}

			if (a[7] == a[4] && a[4] == a[1] && a[1] != " ")
				if (a[7] == "x") {
					winner = 1;
					quit = true;
				}
				else
					if (a[7] == "o")
					{
						winner = 2;
						quit = true;
					}

			if (a[7] == a[5] && a[5] == a[3] && a[3] != " ")
				if (a[7] == "x") {
					winner = 1;
					quit = true;
				}
				else
					if (a[7] == "o")
					{
						winner = 2;
						quit = true;
					}

			if (a[8] == a[5] && a[5] == a[2] && a[2] != " ")
				if (a[8] == "x") {
					winner = 1;
					quit = true;
				}
				else
					if (a[8] == "o")
					{
						winner = 2;
						quit = true;
					}

			if (a[8] == a[5] && a[5] == a[2] && a[2] != " ")
				if (a[8] == "x") {
					winner = 1;
					quit = true;
				}
				else
					if (a[8] == "o")
					{
						winner = 2;
						quit = true;
					}

			if (a[4] == a[5] && a[5] == a[6] && a[6] != " ")
				if (a[4] == "x") {
					winner = 1;
					quit = true;

				}
				else
					if (a[4] == "o")
					{
						winner = 2;
						quit = true;

					}

			if (a[1] == a[2] && a[2] == a[3] && a[3] != " ")
				if (a[1] == "x") {
					winner = 1;
					quit = true;

				}
				else
					if (a[1] == "o")
					{
						winner = 2;
						quit = true;

					}

			if (a[1] == a[5] && a[5] == a[9] && a[9] != " ")
				if (a[1] == "x") {
					winner = 1;
					quit = true;

				}
				else
					if (a[1] == "o")
					{
						winner = 2;
						quit = true;

					}

			if (a[9] == a[6] && a[6] == a[3] && a[3] != " ")
				if (a[9] == "x") {
					winner = 1;
					quit = true;

				}
				else
					if (a[9] == "o")
					{
						winner = 2;
						quit = true;

					}

			if (quit == true) {
				if (winner == 1) {
					if(playervscomputer->getsymbol() == "x")
						cout << endl << endl << "YOU(X) WIN!" << endl;
					else
						if(computer->GetSymbol()=="x")
							cout << endl << endl << "YOU(O) LOSE!" << endl;
				}

				else
					if (winner == 2) {
						if (playervscomputer->getsymbol() == "o")
							cout << endl << endl << "YOU(O) WIN!" << endl;
						else
							if (computer->GetSymbol() == "o")
								cout << endl << endl << "YOU(X) LOSE!" << endl;
					}
			}

			if (emptyCount == 0 && winner == 0) {
				cout << endl << endl;
				cout << "DRAW!" << endl;
				quit = true;
			}
		
	}



	// player vs player
	void Inputpvplayer() {
		if (!quit) {


				if (lastchar == ".") {
					currentchar = player1->getsymbol();
					lastchar = currentchar;
					cout << endl << endl;
					cout << "Choose a position for "<<player1->getsymbol()<<" :";
					player1->setpoz();
					pozx = player1->getpoz();
					if (indexarray[pozx ] != 0) {
						Draw();
						a[pozx] = currentchar;
						indexarray[pozx] = 0;
						Draw();
					}
					else
					{
						do
						{
							cout <<  "An available position please:";
							player1->setpoz();
							pozx = player1->getpoz();
						} while (indexarray[pozx ] == 0);
						a[pozx] = currentchar;
						indexarray[pozx ] = 0;
						Draw();
					}

					
				}



				else if (lastchar == player1->getsymbol()) {
					currentchar = player2->getsymbol();
					lastchar = currentchar;
					cout << endl << endl;
					cout << "Choose a position for " << player2->getsymbol() << " :";
					player2->setpoz();
					pozo = player2->getpoz();
					if (indexarray[pozo ] != 0) {
						Draw();
						a[pozo] = currentchar;
						indexarray[pozo ] = 0;
						Draw();
					}
					else
					{
						do
						{
							cout <<  "An available position please:";
							player2->setpoz();
							pozo = player2->getpoz();
						} while (indexarray[pozo ] == 0);
						a[pozo] = currentchar;
						indexarray[pozo ] = 0;
						Draw();
					}
				}



				else if (lastchar == player2->getsymbol()) {
					currentchar = player1->getsymbol();
					lastchar = currentchar;
					cout << endl << endl;
					cout << "Choose a position for " << player1->getsymbol() << " :";
					player1->setpoz();
					pozx = player1->getpoz();
					if (indexarray[pozx ] != 0) {
						Draw();
						a[pozx] = currentchar;
						indexarray[pozx ] = 0;
						Draw();
					}
					else
					{
						do
						{
							cout <<  "An available position please:";
							player1->setpoz();
							pozx = player1->getpoz();
						} while (indexarray[pozx ] == 0);
						a[pozx] = currentchar;
						indexarray[pozx ] = 0;
						Draw();
					}
				}
			}
			
		}
	
	void Logicpvplayer() {

		int emptyCount = 0;
		for (int i = 1; i <= 9; i++) {
			if (a[i] == " ") {
				emptyCount++;
			}
		}

		if (a[7] == a[8] && a[8] == a[9] && a[9] != " ")
			if (a[7] == "x") {
				winner = 1;
				quit = true; 
			}
			else
				if (a[7] == "o")
				{
					winner = 2;
					quit = true; 
				}

		if (a[7] == a[4] && a[4] == a[1] && a[1] != " ")
			if (a[7] == "x") {
				winner = 1;
				quit = true;
			}
			else
				if (a[7] == "o")
				{
					winner = 2;
					quit = true; 
				}

		if (a[7] == a[5] && a[5] == a[3] && a[3] != " ")
			if (a[7] == "x") {
				winner = 1;
				quit = true; 
			}
			else
				if (a[7] == "o")
				{
					winner = 2;
					quit = true; 
				}

		if (a[8] == a[5] && a[5] == a[2] && a[2] != " ")
			if (a[8] == "x") {
				winner = 1;
				quit = true; 
			}
			else
				if (a[8] == "o")
				{
					winner = 2;
					quit = true; 
				}

		if (a[8] == a[5] && a[5] == a[2] && a[2] != " ")
			if (a[8] == "x") {
				winner = 1;
				quit = true; 
			}
			else
				if (a[8] == "o")
				{
					winner = 2;
					quit = true; 
				}

		if (a[4] == a[5] && a[5] == a[6] && a[6] != " ")
			if (a[4] == "x") {
				winner = 1;
				quit = true;
			
			}
			else
				if (a[4] == "o")
				{
					winner = 2;
					quit = true;
					
				}

		if (a[1] == a[2] && a[2] == a[3] && a[3] != " ")
			if (a[1] == "x") {
				winner = 1;
				quit = true;
				
			}
			else
				if (a[1] == "o")
				{
					winner = 2;
					quit = true;
				
				}

		if (a[1] == a[5] && a[5] == a[9] && a[9] != " ")
			if (a[1] == "x") {
				winner = 1;
				quit = true;
				
			}
			else
				if (a[1] == "o")
				{
					winner = 2;
					quit = true;
					
				}

		if (a[9] == a[6] && a[6] == a[3] && a[3] != " ")
			if (a[9] == "x") {
				winner = 1;
				quit = true;
				
			}
			else
				if (a[9] == "o")
				{
					winner = 2;
					quit = true;
					
				}

		if (quit == true) {
			if (winner == 1) {
				cout << endl << endl << "PLAYER1(X) WINS!" << endl;
			}
				
			else
				if (winner == 2) {
					cout << endl << endl << "PLAYER2(O) WINS!" << endl;
				}

		}

		if (emptyCount == 0 && winner==0) {
			cout << endl << endl;
			cout << "DRAW!" << endl;
			quit = true;
		}
	};



	void RUN() {

		if (messagechoose == "pvp" && messageyes == "YES")
			while (!quit) {
				Draw();
				Inputpvplayer();
				Logicpvplayer();
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		else
			if (messagechoose == "pvc" && difficulty == "easy") {

				playervscomputer->setsymbol();
				if (playervscomputer->getsymbol() == "o") {
					computer->SetSymbol("x");
				}
				else
					if (playervscomputer->getsymbol() == "x") {
						computer->SetSymbol("o");
					}

				while (!quit) {
					Draw();
					Inputpvcomputereasy();
					Draw();
					Logicpvcomputer();
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
			}
			else
				if (messagechoose == "pvc" && difficulty == "medium") {
					playervscomputer->setsymbol();
					if (playervscomputer->getsymbol() == "o") {
						computer->SetSymbol("x");
					}
					else
						if (playervscomputer->getsymbol() == "x") {
							computer->SetSymbol("o");
						}
					while (!quit) {
						Draw();
						Inputpvcomputermedium();
						Draw();
						Logicpvcomputer();
						std::this_thread::sleep_for(std::chrono::milliseconds(10));
					}
				}
				else
					 if (messagechoose == "pvc" && difficulty == "impossible") {
						playervscomputer->setsymbol();
						if (playervscomputer->getsymbol() == "o") {
							computer->SetSymbol("x");
						}
						else
							if (playervscomputer->getsymbol() == "x") {
								computer->SetSymbol("o");
							}
						while (!quit) {
							Draw();
							Inputpvcomputerimpossible();
							Draw();
							Logicpvcomputer();
							std::this_thread::sleep_for(std::chrono::milliseconds(10));
						}
					}
	}


private:
	string  messagechoose,messageyes,difficulty,lastchar = ".", currentchar;
	string  a[10] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	bool  quit;
	bool playerturn ;
	int indexarray[10] = {0,1,2,3,4,5,6,7,8,9};
	int pozx, pozo,winner=0,pozplayer, computerPosition;

	PlayerX* player1;
	PlayerO* player2;
	PLAYER* playervscomputer;
	COMPUTER* computer;

	friend class PlayerX;
	friend class PlayerO;
	friend class PLAYER;
	friend class COMPUTER;
};
