
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor1.ke = 0.24;//1.18; //0.24
	fb_motor1.Tm = 0.1;//0.17;//0.1
	fb_motor1.u = 0;
	fb_motor1.dt = 0.01;
	
	fb_motor2.ke = 0.24;
	fb_motor2.Tm = 0.1;
	fb_motor2.u = 0;
	fb_motor2.dt = 0.01;

	fb_controller.k_p = 0.78;
	fb_controller.k_i = 7.2;
	fb_controller.max_abs_value = 24.0;
	fb_controller.dt = 0.01;
	
	speed = 0;
	counter = 0;
	enable = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(enable)
	{
		if(counter == 200)
		{
			speed = 0;
			counter = 0;
		}
		else if(counter == 50)
		{
			speed = 50;
		}
		fb_controller.e_in = speed - fb_motor1.w;
		FB_Controler(&fb_controller);
		
		fb_motor1.u = fb_controller.u;
		FB_Motor(&fb_motor1);
		
		fb_motor2.u = speed * fb_motor2.ke;
		FB_Motor(&fb_motor2);
		
		counter++;
	}
}

void _EXIT ProgramExit(void)
{

}

