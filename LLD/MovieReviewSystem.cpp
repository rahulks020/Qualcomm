#include<iostream>
#include<string>
#include<vector>

using namespace  std;



class Review
{
     string reviewId;
     string getUniqueReviewId();
     string discription;
     vector<Review>Reviews;

     public:
     Review(string);
     void addNestedReview(Review&);
     string getId();
     void setDescription(string);
     string getDescription();
     vector<Review>& getReviews();
     
 
     void setNestedDescription(string, string);
     void deleteNestedReview(string);

};

Review::Review(string discription)
{
    this->reviewId = getUniqueReviewId();
    this->discription = discription;
}

string Review::getId()
{
    return reviewId;
}

string Review::getUniqueReviewId()
{
    static int id = 1;
    return 'r' + to_string(id++);
}
void Review::addNestedReview(Review& r)
{
      this->Reviews.push_back(r);
}

void Review::deleteNestedReview(string reviewId)
{
    int index = 0;
    for(Review review:Reviews)
    {
        if(review.reviewId == reviewId)
        {
            Reviews.erase(Reviews.begin() + index);
            return;
        }
        index++;
    }
}

string Review::getDescription()
{
      return discription;
}


vector<Review>& Review::getReviews()  {
	return Reviews;
}



class Movie 
{

    string movieId;
    string getUniqueMovieId();
    string description;
    vector<Review>reviews;

    public:

    Movie(string);
    vector<Review>& getReviews();
    string getMovieId();
    void addReview(Review&);
    void addNestedReview(string, Review&);
    void deleteReview(string, string);
    void editReview(string, string, string);
    
} ;


Movie::Movie(string description)
{
     this->description = description;
     this->movieId = getUniqueMovieId();
}

string getUniqueMovieId()
{
    static int movieId = 1;
    return 'm' + to_string(movieId);
}

string Movie::getMovieId()
{
      return movieId;
}

void Movie::addReview(Review & r)
{
     reviews.push_back(r);
}

void Movie::deleteReview(string reviewId, string parentId)
{
    int index = -1, i = 0;
    for(Review review:reviews)
    {
        if(review.getId() == parentId)
        {
            if(parentId == reviewId)
            {
                index = i;
                break;
            }
            else
            {
                 review.deleteNestedReview(reviewId);
                 return;
            }
        }
        index++;
    }

    if(index != -1)
      reviews.erase(reviews.begin() + index);
}

void Movie::editReview(string parentId, string reviewId, string description)
{
   for(Review review:reviews)
   {
       if(review.getId() == parentId)
       {
          if(parentId == reviewId)
          {
            review.setDescription(description);  return;
          }
          else{
             review.setNestedDescription(reviewId, description); return;
          }
       }
   }
}


vector<Review>& Movie::getReviews()  {
	return reviews;
}

class User
{
public:
	User(string);
	void addReviewToMovie(Movie&, Review&);
	void replyToReview(Movie&, string,  Review&);
	bool editReview(Movie&, string, string, string);
	bool deleteReview(Movie&, string, string);
	const string& getId() const;
	const string& getName() const;

private:
	string id;
	string name;
	string getUniqueUserId();
};

User::User(string name)
{
	this->name = name;
	this->id = getUniqueUserId();
}

string User::getUniqueUserId()
{
	static int userId = 1;
	return 'u' + to_string(userId++);
}

void User::addReviewToMovie(Movie& Movie, Review& Review)
{
	
	Movie.addReview(Review);
}
void User::replyToReview(Movie& Movie, string parentId, Review& Review)
{
	
	Movie.addNestedReview(parentId, Review);
}

bool User::editReview(Movie& Movie, string parentId, string ReviewId, string description)
{
	for(Review Review: Movie.getReviews())
	{
		if(Review.getId() == ReviewId)
		{
			// if(Review.getUserId() != this->id)
			// {
			// 	cout << "Unauthorized to edit Review!\n";
			// 	return false;
			// }
			break;
		}
	}

	Movie.editReview(parentId, ReviewId, description);
	return true;
}
bool User::deleteReview(Movie& Movie, string parentId, string ReviewId)
{
	for(Review Review: Movie.getReviews())
	{
		if(Review.getId() == ReviewId)
		{
			// if(Review.getUserId() != this->id)
			// {
			// 	cout << "Unauthorized to delete Review!\n";
			// 	return false;
			// }
			break;
		}
	}

	Movie.deleteReview(parentId, ReviewId);
	return true;
}

const string& User::getId() const {
	return id;
}

const string& User::getName() const {
	return name;
}


int main()
{
    User u1("L");
	Review c1("First Review");
	Review c2("Second Review");
	Review c22("Second nested Review");
	Review c11("First nested Review");
	Review c12("First Second nested Review");
	Review c13("First Third nested Review");

	Movie p;
	u1.addReviewToMovie(p, c1);
	u1.addReviewToMovie(p, c2);
	u1.replyToReview(p, c1.getId(), c11);
	u1.replyToReview(p, c1.getId(), c12);
	u1.replyToReview(p, c1.getId(), c13);
	u1.replyToReview(p, c2.getId(), c22);

    for (Review c : p.getReviews())
	{
		cout << c.getDescription().c_str() << "\n";
		for (Review cmt : c.getReviews())
			cout << "\t" << cmt.getDescription().c_str() << "\n";
	}

	cout << "***********************************************************************" << endl;

	string s12 = "1st 2nd Review";
	string s11 = "1st 1st Review";

	u1.editReview(p, c1.getId(), c11.getId(), s11) ;

	for (Review c : p.getReviews())
	{
		cout << c.getDescription().c_str() << "\n";
		for (Review cmt : c.getReviews())
			cout << "\t" << cmt.getDescription().c_str() << "\n";
	}


	cout << "***********************************************************************" << endl;

	u1.deleteReview(p, c1.getId(), c12.getId()) ;
	for (Review c : p.getReviews())
	{
		cout << c.getDescription().c_str() << "\n";
		for (Review cmt : c.getReviews())
			cout << "\t" << cmt.getDescription().c_str() << "\n";
	}

	cout << "***********************************************************************" << endl;

	u1.deleteReview(p, c1.getId(), c1.getId()) ;
	for (Review c : p.getReviews())
	{
		cout << c.getDescription().c_str() << "\n";
		for (Review cmt : c.getReviews())
			cout << "\t" << cmt.getDescription().c_str() << "\n";
	}
	return 0;
}
