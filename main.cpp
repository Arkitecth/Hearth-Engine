#include <SDL3/SDL.h>
#include <cstddef>
#include <vector>

struct Vector {
	float x{}; 
	float y{}; 

	Vector(float position_x,float position_y) {
		x = position_x;
		y = position_y; 
	}
}; 


struct Color {
	unsigned int r{}; 
	unsigned int g{}; 
	unsigned int b{}; 
	unsigned int a{}; 
}; 

class Card {
	private:
		Vector position_{0, 0};
		float width_{}; 
		float height_{}; 
		SDL_Renderer* renderer_;
		Color color_; 
	
	public:
		Card(Vector position, float width, float height, SDL_Renderer* renderer, Color color) {
			position_ = position;
			width_ = width;
			height_ = height;
			renderer_ = renderer;
			color_ = color; 
		}

		void draw() {
			SDL_FRect rect{position_.x, position_.y, width_, height_};
			SDL_SetRenderDrawColor(renderer_, color_.r, color_.g, color_.b, color_.a); 
			SDL_RenderRect(renderer_, &rect); 
		}
};

class Deck {
	private:
		std::vector<Card> cards{};
	
	public:
		float spreadAngle{525 / 3.0f}; 
		Deck() {

		}
		void addCard(Card card) {
			cards.push_back(card);
		}

		void drawDeck() {
			for (Card& card: cards) {
				card.draw();
			}
		}
}; 

int main() 
{
	SDL_Window* window{};
	SDL_Renderer* renderer{};
	SDL_CreateWindowAndRenderer("Hearth Engine", 800, 800, SDL_WINDOW_ALWAYS_ON_TOP, &window, &renderer); 
	Deck deck1{};
	Deck deck2{};

	//Player 1
	Card card{Vector{200.0f, 0.0f}, 125.0f, 175.0f, renderer, Color{255, 0, 0, 1}};
	Card card2{Vector{350.0f, 0.0f}, 125.0f, 175.0f, renderer, Color{255, 0, 0, 1}};
	Card card3{Vector{500.0f, 0.0f}, 125.0f, 175.0f, renderer, Color{255, 0, 0, 1}}; 

	deck1.addCard(card); 
	deck1.addCard(card2); 
	deck1.addCard(card3); 

	//Player 2
	Card card4{Vector{200.0f, 600.0f}, 125.0f, 175.0f, renderer, Color{0, 0, 255, 1}};
	Card card5{Vector{350.0f, 600.0f}, 125.0f, 175.0f, renderer, Color{0, 0, 255, 1}};
	Card card6{Vector{500.0f, 600.0f}, 125.0f, 175.0f, renderer, Color{0, 0, 255, 1}};

	deck2.addCard(card4); 
	deck2.addCard(card5); 
	deck2.addCard(card6); 

	bool done = false;
	while (!done) {
		SDL_Event e; 
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				done = true;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
		SDL_RenderClear(renderer); 
		deck1.drawDeck(); 
		deck2.drawDeck(); 
		SDL_RenderPresent(renderer); 

	}
}
