#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

/*

Observer Pattern of LLD

*/
class ISubscriber {
    public:
        virtual void notify(string message) = 0;
        virtual ~ISubscriber() {}
};

class User : public ISubscriber{
    private:
        string userId;
    public:
        User(string userId){
            this -> userId = userId;
        }

        void notify(string message){
            cout << "User " << userId << " receives notification " << message << endl; 
        }
};

class Group {
    private:
        vector<ISubscriber*> subscribers;
    public:
        void addSubscriber(ISubscriber* subscriber){
            subscribers.push_back(subscriber);
        }
        void unSubscribeUser(ISubscriber* subscriber) {
            for(auto it = subscribers.begin(); it != subscribers.end(); ++it){
                if(*it == subscriber){
                    it = subscribers.erase(it); // Erase element and update iterator
                    return;
                }
            }
        }
        void notifyUsers(string message){   
            for(ISubscriber* subscriber: subscribers){
                subscriber -> notify(message);
            }
        }

};


int main(){
    // Creating the group to add users, who can observe
    Group* grp = new Group();
    
    // Adding all the observers/users 
    grp->addSubscriber(new User("1"));
    grp->addSubscriber(new User("2"));
    User* user3 = new User("3");
    grp->addSubscriber(user3);
    grp->addSubscriber(new User("4"));
    grp->addSubscriber(new User("5"));

    // Observing.....
    grp->notifyUsers("All Users added");

    // Updating the observers list
    grp->unSubscribeUser(user3);

    // Observing....
    grp->notifyUsers("User 3 removed");
}