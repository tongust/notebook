[TOC]
[**Google C++ Style Guid**](https://google.github.io/styleguide/cppguide.html)
==========================
# Header Files
## Self-contained Headers
- Header files should be self-contained (compile on their own) and end in .h.
- Non-header files that are meant for inclusion should end in .inc and be used sparingly.
- Prefer placing the definitions for template and inline functions in the same file as their declarations.
## The #define Guard
To guarantee uniqueness
```{cpp}
#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_
// Code here
#endif  /* FOO_BAR_BAZ_H_ */
```
## Forward Declarations
Avoid it!

> A "forward declaration" is a declaration of a class, function, or template without an associated definition.

## Inline Functions
- Define functions inline only when they are small, say, 10 lines or fewer.

## Names and Order of Includes
- The use of UNIX directory shortcuts . or .. should be deprecated.
Order of *includes*:
- 1. dir2/foo1.h
- 2. C system files.
- 3. C++ system files.
- 4. Other libraries' *.h* files.
- 5. Your project's *.h* files.

Within each section the includes should be ordered alphabetically.

# Scope
## Namespaces
```{cpp}
/* In the .h file */

namespace mynamespace {
        // Declarations.
} // namespace mynamespace

/* In the .cc file */

namespace mynamespace {
        // Definitions.
} // namespace mynamespace
```
- Do not declare anything in namespaces *std*, becourse declaring entities in namespae *std* is undefined behavior.
- May not use a *using-directive* to make all names from a namespace available.
```{cpp}
using namespace std; /* Should be forbidden */
```
- Do not use *Namespace aliases* at namespace scope in header files except in explicitly marked interal-only namespaces.
```{cpp}
// Shorten access to some commonly used names in .cc files.
namespace baz = ::foo::bar::baz;
```
- Do not use inline namespaces.

## Unnamed Namespaces and Static Variables
When definitions in a *.cc* file do not need to be referenced outside that file, place them in an unnamed namespace or declare them **static**. Don not use either of construts in *.h* files.
```{cpp}
/* unnameed namespace */
namespace {
        Var used_only_inernal;
} // unnamed namespace

/* Alternatives */
static Var used_only_inernal;
```
- All declarations can be given **internal linkage** by placing them in unnamed namespcaes.
- All declarations of functions and variables can be given internal linkage by declaring them **static**.

**Decision**
- Use internal linkage in *.cc* files
- Do not use internal linkage in *.h* files.

## Nonmember, Static Member, and Global Functions













































# Scoping
# Classes
# Functions
# Google-Specific Magic
# Other C++ Features
# Naming
# Comments
# Formatting
# Exceptions to the Rules
