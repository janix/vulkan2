#include "lesson05.h"

namespace JanixVulkan {
	bool LoadFunctionExportedFromVulkanLoaderLibrary(LIBRARY_TYPE const & vulkan_library) {
#if defined _WIN32
	#define LoadFunction GetProcAddress
#elif defined __linux
	#define LoadFunction dlsym
#endif

#define EXPORTED_VULKAN_FUNCTION( name )								\
	name = (PFN_##name)LoadFunction( vulkan_library, #name );			\
	if ( name == nullptr ) {											\
		std::cout << "Could not load exported Vulkan function named: "	\
			#name << std::endl;											\
		return false;													\
}
#include "../Common/ListOfVulkanFunctions.inl"
		return true;
	}
}
