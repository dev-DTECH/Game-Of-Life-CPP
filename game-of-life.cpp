#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <SFML/Graphics.hpp>

const int n = 250;
int WIDTH = 500;
int HEIGHT = 500;
int CELL_SIZE;
const int UNDER_POP = 2;
const int OVER_POP = 3;
const int FPS = 10;
const std::string WINDOW_TITLE = "Game Of Life | DTECH";

int ar[n][n];

int old_ar[n][n];

int countAlive(int ar[n][n], int x, int y)
{
	int c = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			int x1 = i, y1 = j;

			if (i == -1)
				x1 = n - 1;
			if (i == n)
				x1 = 0;
			if (j == -1)
				y1 = n - 1;
			if (j == n)
				y1 = 0;

			if (ar[x1][y1] == 1)
				c++;
		}
	}
	if (ar[x][y] == 1)
		c--;

	return c;
}

int main()
{
	if (WIDTH > HEIGHT)
		CELL_SIZE = HEIGHT / n;
	else
		CELL_SIZE = WIDTH / n;

	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// ar[i][j] = Math.round(Math.random());

			ar[i][j] = rand() % 2;
			// ar[i][j]=0;
			// old_ar[i][j]=ar[i][j];
		}
	}
	ar[12][10] = 1;
	ar[12][11] = 1;
	ar[12][12] = 1;
	ar[13][12] = 1;
	ar[14][11] = 1;

	// old_ar=ar;
	// memcpy(old_ar,ar,sizeof(old_ar));
	// std::copy(std::begin(ar),std::end(ar),std::begin(ar),std::end(ar));

	// std::cout << ar;

	//   for (int i = 0; i < n; i++) {
	// for (int j = 0; j < n; j++) {
	// 	std::cout << ar[i][j];
	// 	// ar[i][j] = Math.round(Math.random());
	// 	// ar[i][j] = 0;
	// 	// old_ar[i][j]=ar[i][j];
	// }
	// 	std::cout << "\n";
	//   }
	sf::VertexArray cells;
	cells.setPrimitiveType(sf::Quads);
	cells.resize(n * n * 4);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sf::Vertex *quad = &cells[(i + j * n) * 4];
			quad[0].position = sf::Vector2f(i * CELL_SIZE, j * CELL_SIZE);
			quad[1].position = sf::Vector2f((i + 1) * CELL_SIZE, j * CELL_SIZE);
			quad[2].position = sf::Vector2f((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
			quad[3].position = sf::Vector2f(i * CELL_SIZE, (j + 1) * CELL_SIZE);
			if (ar[i][j] == 1)
			{
				quad[0].color = sf::Color::Black;
				quad[1].color = sf::Color::Black;
				quad[2].color = sf::Color::Black;
				quad[3].color = sf::Color::Black;
			}
			else
			{
				quad[0].color = sf::Color::White;
				quad[1].color = sf::Color::White;
				quad[2].color = sf::Color::White;
				quad[3].color = sf::Color::White;
			}
		}
	}

	sf::Clock clock;

	sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	cell.setFillColor(sf::Color(0, 0, 0));

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	sf::Event event;

	unsigned int frameCounter = 0;

	while (window.isOpen())
	{
		frameCounter++;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
			if (event.type == sf::Event::Resized)
			{
				std::cout << event.size.width << "," << event.size.height << "\n";
				// WIDTH=event.size.width;
				// HEIGHT=event.size.height;
				// if(WIDTH>HEIGHT)
				// 	CELL_SIZE=HEIGHT/n;
				// else
				// 	CELL_SIZE=WIDTH/n;
			}
			/*if (event.type == sf::Event::KeyReleased) playerTextureRect.left = 0;*/

			/*if (event.type == sf::Event::MouseButtonPressed) std::cout << event.mouseButton.button << " is pressed\n";

			if (event.type == sf::Event::MouseMoved) std::cout << "Mouse moved\n";*/
		}
		if (clock.getElapsedTime().asMilliseconds() >= 1000)
		{
			std::cout << "FPS : " << frameCounter << "\n";
			clock.restart();
			frameCounter = 0;
		}
		// double dt = clock.getElapsedTime().asMilliseconds();
		window.clear(sf::Color(255, 255, 255));

		memcpy(old_ar, ar, sizeof(old_ar));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int noOfAliveCells = countAlive(old_ar, i, j);
				// sf::Vertex* quad =&cells[(i+j*n)*4];

				if (old_ar[i][j] == 1)
				{

					// quad[0].color=sf::Color::Black;
					// quad[1].color=sf::Color::Black;
					// quad[2].color=sf::Color::Black;
					// quad[3].color=sf::Color::Black;

					cell.setPosition(sf::Vector2f(j * CELL_SIZE, i * CELL_SIZE));
					window.draw(cell);
					if (noOfAliveCells > OVER_POP || noOfAliveCells < UNDER_POP)
						ar[i][j] = 0;
				}
				else
				{
					if (noOfAliveCells == OVER_POP)
						ar[i][j] = 1;
					// sf::Vertex* quad =&cells[(i+j*n)*4];

					// quad[0].color=sf::Color::White;
					// quad[1].color=sf::Color::White;
					// quad[2].color=sf::Color::White;
					// quad[3].color=sf::Color::White;
				}

				// std::cout << ar[i][j];
				// ar[i][j] = Math.round(Math.random());
				// ar[i][j] = 0;
				// old_ar[i][j]=ar[i][j];
			}
			// std::cout << "\n";
		}

		// window.draw(cells);

		window.display();
	}
	return EXIT_SUCCESS;
}