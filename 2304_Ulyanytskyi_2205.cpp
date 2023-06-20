#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename type>
type get_user_value() {
    type value;
    cout << "Enter: ";
    cin >> value;
    return value;
}

struct Film
{
    string name;
    string genre;
    string director;
    float rating;
    float price;
};

void display_film(const Film& film)
{
    cout << "Name: " << film.name << endl;
    cout << "Genre: " << film.genre << endl;
    cout << "Director: " << film.director << endl;
    cout << "Rating: " << film.rating << endl;
    cout << "Price: " << film.price << endl;
    cout << endl;
}

void search_by_name(const vector<Film>& films, const string& name)
{
    bool found = false;
    for (const Film& film : films)
    {
        if (film.name == name)
        {
            display_film(film);
            found = true;
        }
    }

    if (!found)
    {
        cout << "Film with name " << name << " not found." << endl;
    }
}

void search_by_genre(const vector<Film>& films, const string& genre)
{
    bool found = false;
    for (const Film& film : films) {
        if (film.genre == genre) {
            display_film(film);
            found = true;
        }
    }

    if (!found) {
        cout << "Films with genre " << genre << " not found." << endl;
    }
}

void search_by_director(const vector<Film>& films, const string& director)
{
    bool found = false;
    for (const Film& film : films) {
        if (film.director == director) {
            display_film(film);
            found = true;
        }
    }

    if (!found) {
        cout << "Films directed by " << director << " not found." << endl;
    }
}

void search_most_popular(const vector<Film>& films, const string& genre)
{
    float max_rating = 0.0;
    const Film* most_popular_film = nullptr;

    for (const Film& film : films) {
        if (film.genre == genre && film.rating > max_rating) {
            max_rating = film.rating;
            most_popular_film = &film;
        }
    }

    if (most_popular_film != nullptr) {
        cout << "Most popular film in the genre " << genre << ":" << endl;
        display_film(*most_popular_film);
    }
    else
    {
        cout << "Films with genre " << genre << " not found." << endl;
    }
}

void display_all_films(const vector<Film>& films)
{
    cout << "All Films:\n" << endl;
    for (const Film& film : films) {
        display_film(film);
    }
}

int main()
{
    int menu_choice;
    bool exit_status = false;

    vector<Film> films;

    films.push_back({ "Interstellar", "Sci-fi", "Christopher Nolan", 8.7, 10 });
    films.push_back({ "Dune", "Sci-fi", "Denis Villeneuve", 8.0, 12 });
    films.push_back({ "The Dark Knight", "Action", "Christopher Nolan", 9.0, 12 });
    films.push_back({ "Sicario", "Thriller", "Denis Villeneuve", 7.6, 9 });

    do
    {
        cout << "Movie DB\n";
        cout << "1 - for display all movies\n";
        cout << "2 - for search movie by name\n";
        cout << "3 - for search movie by genre\n";
        cout << "4 - for search movie by director\n";
        cout << "5 - for search the most popular film in the genre\n";
        cout << "6 - for add new movie\n";
        cout << "0 - for Exit\n";

        menu_choice = get_user_value<int>();

        switch (menu_choice)
        {
        case 1:
        {
            display_all_films(films);
            break;
        }            
        case 2:
        {
            string name = get_user_value<string>();
            search_by_name(films, name);
            break;
        }            
        case 3:
        {
            string genre = get_user_value<string>();
            search_by_genre(films, genre);
            break;
        }
        case 4:
        {
            string director = get_user_value<string>();
            search_by_director(films, director);
            break;
        }
        case 5:
        {
            string genre = get_user_value<string>();
            search_most_popular(films, genre);
            break;
        }
        case 6:
        {
            Film new_film;
            cout << "Enter name: ";
            new_film.name = get_user_value<string>();
            cout << "Enter genre: ";
            new_film.genre = get_user_value<string>();
            cout << "Enter director: ";
            new_film.director = get_user_value<string>();
            cout << "Enter rating: ";
            new_film.rating = get_user_value<float>();
            cout << "Enter price: ";
            new_film.price = get_user_value<float>();
            films.push_back(new_film);
            cout << "Film added successfully." << endl;
            break;
        }
        case 0:
        {
            exit_status = true;
            cout << "Exit";
            break;
        }
        default:
        {
            cout << "Invalid menu choice. Please try again." << endl;
            break;
        }
        }

    } while (!exit_status);

    return 0;
}