#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

/*

Abstract Factory Pattern of LLD

*/

class IButton{
    public:
        virtual void press() = 0;
};

class AndroidButton : public IButton{
    public:
        void press(){
            cout << "Android Button Pressed" << endl;
        }
};

class IOSButton : public IButton{
    public:
        void press(){
            cout << "IOS Button Presses" << endl;
        }
};


class IText{
    public:
        virtual void showText() = 0;
};

class AndroidText : public IText{
    public:
        void showText(){
            cout << "Android Text Showing" << endl;
        }
};

class IOSText : public IText{
    public:
        void showText(){
            cout << "IOS Text Showing" << endl;
        }
};

class IFactory {
    public:
        virtual IButton* createButton() = 0;
        virtual IText* createText() = 0;
};


class AndroidFactory : public IFactory{
    public:
        IButton* createButton(){
            return new AndroidButton();
        }
        IText* createText(){
            return new AndroidText();
        }
};


class IOSFactory : public IFactory{
    public:
        IButton* createButton(){
            return new IOSButton();
        }
        IText* createText(){
            return new IOSText();
        }
};

class GUIAbstractFactory {
    public:
        static IFactory* createFactory(string osType){
            if(osType == "Android"){
                return new AndroidFactory();
            }
            else {
                return new IOSFactory();
            }
        }
};

int main()
{
    int osType;
    cout << "Enter Prefered OS Type (1) Android (2) iOS : ";
    cin >> osType;
    IFactory* fact = GUIAbstractFactory :: createFactory(osType == 1? "Android" : "iOS");

    IButton* button = fact->createButton();
    IText* text = fact->createText();

    button->press();
    text->showText();


}
