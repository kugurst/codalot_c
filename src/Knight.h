class Knight {
private:
    int xp;
    int stamina;
    bool inTavern;
    bool inTrainingYard;

public:
    Knight();
    int getXp();
    void setXp(int xp);
    void incrementXp(int xp);
    int getStamina();
    void setStamina(int stamina);
    void incrementStamina(int stamina);
    bool isInTavern();
    void setInTavern(bool inTavern);
    bool isInTrainingYard();
    void setInTrainingYard(bool inTrainingYard);
};