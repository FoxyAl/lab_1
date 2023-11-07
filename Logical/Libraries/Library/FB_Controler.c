
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Controler(struct FB_Controler* inst)
{
	/*TODO: Add your code here*/
	REAL a = inst->e_in * inst->k_p;
	REAL b = inst->e_in * inst->k_i;
	
	//ограничение напряжения
	a = a > inst->max_abs_value ?  inst->max_abs_value : a;
	a = a < -inst->max_abs_value ? -inst->max_abs_value : a;
	
	inst->integrator.in = b + inst->sum;
	FB_integrator(&inst->integrator);
	
	REAL sum = a + inst->integrator.out;
	inst->u = sum;
	
	inst->u = sum;
	
	inst->u = inst->u > inst->max_abs_value ? inst->max_abs_value : inst->u;
	inst->u = inst->u < -inst->max_abs_value ? -inst->max_abs_value : inst->u;
	
	inst->sum = inst->u - sum;
	
	
//	if(abs(a) < inst->max_abs_value)
//	{
//		a = a;
//	}
//	else
//	{
//		if(a < 0)
//		{
//			a = (-1)*inst->max_abs_value
//		}
//		else
//		{
//			a = inst->max_abs_value
//		}
//	}
}
