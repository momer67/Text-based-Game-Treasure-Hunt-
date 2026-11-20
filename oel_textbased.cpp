#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void applyCarryOnBonus(double &hearts, int attempts) {
    if (attempts == 1)
    {
        hearts += 1.0; cout << "[Bard]: You got it on the first try, Oh mighty plunderer, may the pirates of old be with thee!! [+1 Hearts]\n";
    }
    else if (attempts >= 2 && attempts <= 4)
    {
        hearts += 0.5; cout << "[Bard]: A pirate, true and blue, strives through the gloomy woo of miscues!! (even if it left this particular pirate with "<<attempts<<" attempts) [+0.5 Hearts]\n";
    }
    else {
        cout << "[Bard]: Unfortunately, the council of the pirates have decided to not apportion more hearts, may thee strive hard and fast for what comes ahead!!\n";
    }
}

void gameIntro() {
    string ContinueGame; string PayingAtt; bool PayingAttention; bool ContinueGameBool; int ContinueGameBoolFailCount=0; int PayingAttentionFailCount=0;
    cout << "=========================================================\n";
    cout << "                  THE TREASURE HUNT                  \n";
    cout << "=========================================================\n\n";
    cout << "[Bard]: Hark, ye scallywag! Thou claimest to be a mighty pirate of the high seas, yet thou speakest in the tongue of the Bard himself!! \n";
    cout << "[Bard]: Yet, i shall guide thee!! (Bard's inner voice (Silly Sam): since the job market seems bleak in fortune)\n\n";
    cout << "================== THE RULES ============================ \n\n";
    cout << "[Bard]: NOT PAYING ATTENTION HERE MIGHT COST YOU... (are you paying attention?...)\n";
    do{
        cout << "[Bard]: Yes or No: "; cin>>PayingAtt;
        PayingAttention = (((PayingAtt)=="Yes") ||  ((PayingAtt)=="yes")   ||  ((PayingAtt)=="YES"))? 1:0;
        if (PayingAttention==0) {
            cout << "[Bard]: You have chosen NOT to pay attention, an act of BLASPHEMY, TREASON and unprecedented NEGLIGENCE!!\n...\n...\n...\n[Bard]: (Silly Sam): Are you paying attention now? \n";
            PayingAttentionFailCount++;
            if (PayingAttentionFailCount==2) {
                cout << "[Bard]: You have committed BLASPHEMY AND TREASON ONCE MORE!! Repent 'O plunderer of the high seas!!...\n";
            }
            if (PayingAttentionFailCount>=3) {
                cout << "[Bard]: You have shown disregard for the Bard's guidance (Silly Sam: And a wretched pitiable attention span!!)\n";
                cout << "[Bard]: and thus you are cast into the depths of the sea, never to be seen again!!\n";
                cout << "[Bard]: The aura loss was palpable, so much so that the council of pirates have decided to revoke your pirate status, and you are now a landlubber, forevermore!!\n";
                exit(0);
            }
        }
    } while (!(PayingAttention));
    cout<<  "[Bard]: You have chosen to pay attention, a wise choice, for the path ahead is treacherous and full of peril!!\n";
    cout << "[Bard]: Solve puzzles that lead thee closer to treasure across 4 different encryption levels.\n";
    cout << "        You start with 5 lives per level, O' pirate\n";
    cout << "        Carry-On System: Leftover hearts carry over as per these rules for ye hunt to be of ease:\n";
    cout << "          - if a puzzle is solved in 1 try: +1.0 Full Heart\n";
    cout << "          - if a puzzle is solved in 2-4 tries: +0.5 Half Heart\n";
    cout << "          - if a puzzle is solved on 5th try: +0.0 Hearts\n";
    cout << "          - If your available tries drop to 0, you reset to Level 1 (doom and gloom ye see!!)\n";
    cout << "        If you solve all 4 stages of this quest, thee shall be rewarded with endless gold and glory (+aura)!!\n";
    cout << "        Good luck, O' pirate, and may the winds of fortune be at your back!!\n";
    cout << "       ======================================================================================================\n";
    do{
        cout << "[Bard]: Do you wish to continue? (Yes or No): "; cin>>ContinueGame;
        ContinueGameBool = (((ContinueGame)=="Yes") ||  ((ContinueGame)=="yes")   ||  ((ContinueGame)=="YES"))? 1:0;
        if (ContinueGameBool==0) {
            cout << "[Bard]: You have chosen the path of cowardice and of endless shame, but yet we ask again!\n";
            ContinueGameBoolFailCount++;
            if (ContinueGameBoolFailCount==2) {
                cout << "[Bard]: You have chosen the path of cowardice and of endless shame RATHER SHAMELESSLY ONCE MORE!! (beware [game tip]: refrain from further loss of aura and repent) \n";
            }
            if (ContinueGameBoolFailCount>=3) {
                cout << "[Bard]: You have failed to choose the path of courage and honor, and thus you are cast into the depths of the sea, never to be seen again!!\n";
                cout << "[Bard]: The aura loss was palpable, so much so that the council of pirates have decided to revoke your pirate status, and you are now a landlubber, forevermore!!\n";
                exit(0);
            }
        }
    }while (ContinueGameBool==0);
    cout << "[Bard]: You have chosen to continue, a wise choice, for the path ahead is treacherous and full of peril!!\n";
    cout << "[Bard]: The council of pirates have decided to bestow upon thee the title of 'Mighty Plunderer of the High Seas'!!\n";
    cout << "[Bard]: Now we shall begin!! (*Silly Sam whispers: Thee shall find your way, as you always do!)\n";
    cout << "=========================================================\n";
}

void displayHearts(double hearts) {
    int fullHearts = static_cast<int>(floor(hearts)); // actual tries but we need to separate these 2 values to check the HasHalfHeart bool
    bool HasHalfHeart = (hearts - fullHearts) >= 0.5;
    cout << "\n [Hearts left: " << hearts << " ]\n";
    for (int i = 0; i < fullHearts; i++)
    {
        cout << "\033[91m<3\033[0m ";
    }
    if (HasHalfHeart)
    {
        cout << "\033[91m<\033[0m";
    }
    cout << "\n";
}

void gameReset(double *hearts, int *currentLevel) {
    bool inDenial = true; string testDenial; int denialCount = 0;
    cout << "[Bard]: You were given every chance...\n";
    cout << "[Bard]: Yet, you failed the Bard (Silly Sam: and me toooooo!!!) in this test of faith\n";
    do{
        cout << "[Bard]: You have failed, Have you not??...(*Hans Landa impression intensifies*)\n"; cin>>testDenial;
        inDenial = (((testDenial)=="No") ||  ((testDenial)=="no")   ||  ((testDenial)=="NO"))? 1:0;
        if (inDenial==1) {
            cout << "[Bard]: Lies...Lies...Lies...In Denial I see, I shall ask again...\n";
            denialCount++;
            switch (denialCount) {
                case 1:
                    cout << "([game tip]: refrain from further loss of aura for which 17 generations of yee plunderin' mateys might see aura debt)...\n";
                    cout << "([game tip]: The fate of the whole world rests on your next input)\n\n";
                    break;
                case 2:
                    cout << "([game tip]: refrain from further loss of aura for which 18 generations of yee plunderin' mateys might see aura debt)...\n";
                    cout << "([game tip]: The fate of the whole world might not actually rest on your next input it seems)\n\n";
                    break;
                case 3:
                    cout << "\n\n[Bard]: Yarrr, our unfortunate wanderer is lost—lacking focus in navigating deceptive yarns or unraveling riddles, We abandon ye!\n";
                    cout << "[Bard]: Yet one unyielding adventurer learns wisely after yesteryear's slipups, destined onward!\n";
                    cout << "        ([Life tip]: Read the sentence that forms when you read each beginning letter of the previous messages together)\n\n";
                    inDenial = 0;
                    break;
                default:
                    cout << "([game tip]: refrain from further loss of aura for which 19 generations of yee plunderin' mateys might see aura debt)...\n";
                    cout << "([game tip]: I dont know how you got here but mad respect for finding a way out of the matrix)\n\n";
                    inDenial = 0;
                    break;
                }
        }
    }while (inDenial==1);
    if (inDenial==0) {
        cout << "[Bard]: You have chosen to accept your fate, a wise choice!! but yet... you still failed\n";
        cout << "[Bard]: Now we shall begin, oncemore!! (*Silly Sam whispers: Thee shall find your way, as you always do!)\n";
        *hearts = 5.0; *currentLevel = 1;
    }
}




int main(){
    gameIntro();
    return 0;
}