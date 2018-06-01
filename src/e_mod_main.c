#include "e.h"
#include "../config.h"/* module setup */


static E_Action *act;

int _quickscreen_log_domain = -1;

E_API E_Module_Api e_modapi =
{
   E_MODULE_API_VERSION,
     "Quickscreen"
};


static void
qs_key(E_Object *obj EINA_UNUSED, const char *params EINA_UNUSED)
{
  printf("QUICKSCREEN\n");
}

E_API void *
e_modapi_init(E_Module *m)
{
  _quickscreen_log_domain = eina_log_domain_register("quickscreen", "red");

  act = e_action_add("qs_key");
  e_action_predef_name_set("Quickscreen", "Toogle Screenlayout Popup", "qs_key", NULL, NULL, 0);
  act->func.go = qs_key; 

  return m;
}

E_API int
e_modapi_shutdown(E_Module *m EINA_UNUSED)
{
   /* your code-shutdown */
	
   E_FREE_FUNC(act, e_action_del);
   e_action_predef_name_del("Quickscreen", "qs_key");
	
   return 1;
}

E_API int
e_modapi_save(E_Module *m EINA_UNUSED)
{
   /* your code-save */
   return 1;
}
