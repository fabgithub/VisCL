#ifndef CL_TASK_REGISTRY
#define CL_TASK_REGISTRY

#include "cl_task.h"
#include <boost/make_shared.hpp>

#define NEW_TASK(T) boost::shared_ptr<T>((T *)cl_task_registry::inst()->new_task(vcl_string(#T)))

class cl_task_registry
{
public:

  static cl_task_registry *inst();

  cl_task *new_task(const vcl_string &task_name);

private:

  cl_task_registry();
  static cl_task_registry *inst_;

  vcl_map<vcl_string, cl_task *> tasks;
};

#endif