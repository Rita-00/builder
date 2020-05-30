#include <iostream>

using namespace std;

enum AIRLINE {
  EASYJET,
  REDWINGS,
  RYANAIR
};

string getAirlane(AIRLINE airline) {
  switch (airline) {
  case AIRLINE::EASYJET:
    return "EASYJET";
  case AIRLINE::REDWINGS:
    return "REDWINGS";
  case AIRLINE::RYANAIR:
    return "RYANAIR";
  }
}

enum HOTEL {
  AMBA,
  GENTING,
  TONGTONG,
  LESCAPE
};

string getHotel(HOTEL hotel) {
  switch (hotel) {
  case HOTEL::AMBA:
    return "AMBA";
  case HOTEL::GENTING:
    return "GENTING";
  case HOTEL::TONGTONG:
    return "TONGTONG";
  case HOTEL::LESCAPE:
    return "LESCAPE";
  }
}

enum EAT {
  INHOTEL,
  INDEPENDENTLY
};

string getEat(EAT eat) {
  switch (eat) {
  case EAT::INHOTEL:
    return "INHOTEL";
  case EAT::INDEPENDENTLY:
    return "INDEPENDENTLY";
  }
}

enum ADDITIONALTOUR {
  NONE,
  VILLAGE,
  PARK
};

string getAdditionaltour(ADDITIONALTOUR additionaltour) {
  switch (additionaltour) {
  case ADDITIONALTOUR::NONE:
    return "NONE";
  case ADDITIONALTOUR::VILLAGE:
    return "VILLAGE";
  case ADDITIONALTOUR::PARK:
    return "PARK";
  }
}

class TravelInKorea {
  AIRLINE airline;
  string data;
  unsigned int amountofdays;
  unsigned int numberofpersons;
  bool withkids;
  HOTEL hotel;
  EAT eat;
  bool guide;
  ADDITIONALTOUR additionaltour;

public:
  TravelInKorea(AIRLINE airline, string data, unsigned int amountofdays,
                unsigned int numberofpersons, bool withkids, HOTEL hotel,
                EAT eat, bool guide, ADDITIONALTOUR additionaltour) {
    this->additionaltour = additionaltour;
    this->airline = airline;
    this->amountofdays = amountofdays;
    this->eat = eat;
    this->guide = guide;
    this->hotel = hotel;
    this->withkids = withkids;
    this->data = data;
    this->numberofpersons = numberofpersons;
  }

  void Print() {
    cout << getAirlane(airline) << " ";
    cout << data << " ";
    cout << amountofdays << " ";
    cout << numberofpersons << " ";
    cout << withkids << " ";
    cout << getHotel(hotel) << " ";
    cout << getEat(eat) << " ";
    cout << guide << " ";
    cout << getAdditionaltour(additionaltour) << endl;
  }
};

class TravelInKoreaBuilder {
  AIRLINE airline;
  string data;
  unsigned int amountofdays;
  unsigned int numberofpersons;
  bool withkids;
  HOTEL hotel;
  EAT eat;
  bool guide;
  ADDITIONALTOUR additionaltour;

public:
  void setAirlane(AIRLINE airline) {
    TravelInKoreaBuilder::airline = airline;
  }
  void setData(string data) {
    TravelInKoreaBuilder::data = data;
  }
  void setAmountofdays(unsigned int amountofdays) {
    TravelInKoreaBuilder::amountofdays = amountofdays;
  }
  void setNumberofpersons(unsigned int numberofpersons) {
    TravelInKoreaBuilder::numberofpersons = numberofpersons;
  }
  void setWithkids(bool withkids) {
    TravelInKoreaBuilder::withkids = withkids;
  }
  void setHotel(HOTEL hotel) {
    TravelInKoreaBuilder::hotel = hotel;
  }
  void setEat(EAT eat) {
    TravelInKoreaBuilder::eat = eat;
  }
  void setGuide(bool guide) {
    TravelInKoreaBuilder::guide = guide;
  }
  void setAdditionaltour(ADDITIONALTOUR additionaltour) {
    TravelInKoreaBuilder::additionaltour = additionaltour;
  }

  TravelInKorea *build() {
    return new TravelInKorea(airline, data, amountofdays, numberofpersons,
                             withkids, hotel, eat, guide, additionaltour);
  }
};

int main() {
  TravelInKoreaBuilder builder;

  builder.setAdditionaltour(NONE);
  builder.setAirlane(EASYJET);
  builder.setAmountofdays(7);
  builder.setData("02.07.2021");
  builder.setEat(INHOTEL);
  builder.setGuide(false);
  builder.setHotel(AMBA);
  builder.setNumberofpersons(2);
  builder.setWithkids(false);

  TravelInKorea *Anna;
  Anna = builder.build();
  Anna->Print();

  TravelInKorea *Tom;
  builder.setAirlane(RYANAIR);
  builder.setEat(INDEPENDENTLY);
  builder.setNumberofpersons(3);
  builder.setWithkids(true);

  Tom = builder.build();
  Tom->Print();
}