#include<array>
#include<chrono>
#include<iostream>
#include<memory>
#include<vector>
#include<GLFW/glfw3.h>
#include<BasicEnemy.hpp>
#include<HealthPack.hpp>
#include<utils.hpp>
std::array<unsigned,13>levelTimeStamps = {0, 300, 900, 1800, 3000, 4500, 6300, 8400, 10800, 13500, 16500, 19800, 23400};
std::array<float, 5>player = {0, 0, 0, 0, 120};
std::vector<std::shared_ptr<AbstractEnemy>>enemies;
std::vector<std::shared_ptr<HealthPack>>hpacks;
int main(int argc, char **argv)
{
	if(glfwInit())
	{
		std::mt19937_64 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		GLFWwindow*window=glfwCreateWindow(512,512,"Wave",nullptr,nullptr);
		if(window)
		{
			glfwMakeContextCurrent(window);
			double last=glfwGetTime();
			double now=0;
			double passed=0;
			unsigned score=0;
			unsigned level=0;
			while(!glfwWindowShouldClose(window))
			{
				now=glfwGetTime();
				passed+=now-last;
				last=now;
				if(passed>0.016666667)
				{
					if(score==levelTimeStamps[level])
					{
						enemies.push_back(std::make_shared<BasicEnemy>((float)(mt()%199+1)/150-0.5, (float)(mt()%199+1)/150-0.5, rfloat(mt)/80+0.0125, rfloat(mt)/80+0.0125));
						std::cout<<enemies.size()<<std::endl;
						if(level+1<levelTimeStamps.size())
							++level;
					}

					if(mt()%180==0)
						hpacks.push_back(std::make_shared<HealthPack>((float)(mt()%199+1)/100-1, (float)(mt()%199+1)/100-1, mt()%121+120));

					glClear(GL_COLOR_BUFFER_BIT);
					if(player[4] != 0)
						glColor3ub(255, 0, 255);
					else
						glColor3ub(97, 97, 97);
					FillRect(-1, -1, 2, 2);
					glColor3ub(0, 255, 0);
					FillRect(player[0] - 5.0 / 128, player[1] - 5.0 / 128, 5.0 / 64, 5.0 / 64);

					player[0] += player[2] / 256;
					player[1] += player[3] / 256;

					if(player[4])
					{
						if(glfwGetKey(window, 87))
						{
							player[3] = 1;
						}
						else if(glfwGetKey(window, 83))
						{
							player[3] = -1;
						}
						else
						{
							player[3] = 0;
						}

						if(glfwGetKey(window, 65))
						{
							player[2] = -1;
						}
						else if(glfwGetKey(window, 68))
						{
							player[2] = 1;
						}
						else
						{
							player[2] = 0;
						}
					}

					player[0] = std::max(std::min(player[0], 1.0f - 5.0f / 128), 5.0f / 128 - 1);
					player[1] = std::max(std::min(player[1], 1.0f - 5.0f / 128), 5.0f / 128 - 1);

					for(auto &en : enemies)
					{
						en->run();
						en->render(window);
						if(player[4]&&en->intersects(player[0]-5.0/128,player[1]-5.0/128,5.0/64,5.0/64))
						{
							player[4]-=6;
							player[4]=std::max(player[4],0.0f);
							if(player[4]==0)
							{
								std::cout << "Aww, you lost\nYour score was " << score << std::endl;
							}
						}

						if(en->getX()-en->getW()/2<-1||en->getX()+en->getW()/2>1)
						{
							en->setVelX(en->getVelX()*-1);
						}
						if(en->getY()-en->getH()/2<-1||en->getY()+en->getH()/2>1)
						{
							en->setVelY(en->getVelY()*-1);
						}
					}

					glColor3f(1, 0, 0);
					for(auto it=hpacks.begin();it!=hpacks.end();++it)
					{
						if((*it)->getStrength()==0)
						{
							hpacks.erase(it--);
							continue;
						}
						if((*it)->getY()>player[1]-5.0/128&&(*it)->getY()<player[1]+5.0/128&&(*it)->getX()>player[0]-5.0/128&&(*it)->getX()<player[0]+5.0/128)
						{
							player[4]+=(*it)->getStrength();
							player[4]=std::min(player[4],120.0f);
							hpacks.erase(it--);
							continue;
						}
						FillRect((*it)->getX() - 5.0 / 128, (*it)->getY() - 5.0 / 128, 5.0 / 64, 5.0 / 64);
						--(*it)->getStrength();
					}

					glColor3f(0.5, 0.5, 0.5);
					FillRect(-113.0 / 128, -113.0 / 128, 35.0 / 64, 5.0 / 32);
					glColor3f(0.9, 0.1, 0.1);
					FillRect(-27.0 / 32, -27.0 / 32, 15.0 / 32, 5.0 / 64);
					glColor3f(0.1, 0.9, 0.1);
					FillRect(-27.0 / 32, -27.0 / 32, player[4] / 256, 5.0 / 64);

					glfwSwapBuffers(window);
					glfwPollEvents();
					passed=0;
					score++;
				}
			}
			glfwTerminate();
		}
	}
	return 0;
}
