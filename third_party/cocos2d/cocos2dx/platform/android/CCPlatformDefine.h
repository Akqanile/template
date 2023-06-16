#ifndef __CCPLATFORMDEFINE_H__
#define __CCPLATFORMDEFINE_H__

#define CC_DLL 

#define CC_ASSERT(cond) \
if (! (cond)) \
{ \
    char content[256]; \
    sprintf(content, "%s function:%s line:%d", __FILE__, __FUNCTION__, __LINE__);  \
    CCMessageBox(content, "Assert error"); \
}


#define CC_UNUSED_PARAM(unusedparam) (void)unusedparam

/* Define NULL pointer value */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif



/* cocos2d-x-gd specific macros */

/* Stringification macros */
#define CC_GD_STR2(...) #__VA_ARGS__
#define CC_GD_STR(...) COCOS_GD_STR2(__VA_ARGS__)

/* Concatenation macros */
#define CC_GD_CONCAT2(In1_, In2_) In1_##In2_
#define CC_GD_CONCAT(In1_, In2_) COCOS_GD_CONCAT2(In1_, In2_)

/** @def CC_GD_ADD
 Contained expressions are added by Geometry Dash to cocos2d.
 */
#define CC_GD_ADD(...) __VA_ARGS__

/** @def CC_GD_REMOVE
 Contained expressions are removed by Geometry Dash from cocos2d.
 */
#define CC_GD_REMOVE(...)

/** @def CC_GD_ADD_BEGIN
 Following expressions are added by Geometry Dash to cocos2d.
 */
#define CC_GD_ADD_BEGIN

/** @def CC_GD_ADD_END
 Terminator for CC_GD_ADD_BEGIN.
 */
#define CC_GD_ADD_END

/** @def CC_GD_REMOVE_BEGIN
 Following expressions are removed by Geometry Dash from cocos2d.
 */
#define CC_GD_REMOVE_BEGIN class CC_GD_CONCAT(Removed, __LINE__) {

/** @def CC_GD_REMOVE_END
 Terminator for CC_GD_REMOVE_BEGIN.
 */
#define CC_GD_REMOVE_END };

/** @def CC_GD_NOT_IMPLEMENTED
 Throw not implemented error
 */
#ifdef __cplusplus
    #include <stdexcept>
    #define CC_GD_NOT_IMPLEMENTED() throw std::logic_error("Function not implemented")
#else
    #define CC_GD_NOT_IMPLEMENTED()
#endif


#endif /* __CCPLATFORMDEFINE_H__*/
