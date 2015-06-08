// Generated by Apple Swift version 1.2 (swiftlang-602.0.53.1 clang-602.0.53)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"


/// Mustache templates don't eat raw values: they eat values boxed in <code>MustacheBox</code>.
///
/// To box something in a <code>MustacheBox</code>, you use one variant of the <code>Box()</code>
/// function. It comes in several variants so that nearly anything can be boxed and
/// feed templates:
///
/// <ul><li><p>Basic Swift values:</p><blockquote><p><code>template.render(Box("foo"))</code></p></blockquote></li><li><p>Dictionaries & collections:</p><blockquote><p>template.render(Box(["numbers": [1,2,3]]))</p></blockquote></li><li><p>Custom types via the <code>MustacheBoxable</code> protocol:</p><blockquote><p>extension User: MustacheBoxable { ... }
/// template.render(Box(user))</p></blockquote></li><li><p>Functions such as <code>FilterFunction</code>, <code>RenderFunction</code>, <code>WillRenderFunction</code> and
/// `DidRenderFunction`:</p><blockquote><p>let square = Filter { (int: Int, _) in Box(int * int) }
/// template.registerInBaseContext("square", Box(square))</p></blockquote></li></ul>
/// Warning: the fact that <code>MustacheBox</code> is a subclass of NSObject is an
/// implementation detail that is enforced by the Swift 1.2 language itself. This
/// may change in the future: do not rely on it.
SWIFT_CLASS("_TtC8Mustache11MustacheBox")
@interface MustacheBox : NSObject

/// The only empty box is <code>Box()</code>.
@property (nonatomic, readonly) BOOL isEmpty;

/// The boolean value of the box.
///
/// It tells whether the Box should trigger or prevent the rendering of regular
/// `{{#section}}...{{/}}` and inverted <code>{{^section}}...{{/}}</code>.
@property (nonatomic, readonly) BOOL boolValue;

/// If the boxed value can be iterated (Swift collection, NSArray, NSSet, etc.),
/// returns an array of <code>MustacheBox</code>.
@property (nonatomic, readonly, copy) NSArray * __nullable arrayValue;

/// If the boxed value is a dictionary (Swift dictionary, NSDictionary, etc.),
/// returns a dictionary <code>[String: MustacheBox]</code>.
@property (nonatomic, readonly, copy) NSDictionary * __nullable dictionaryValue;
- (MustacheBox * __nonnull)objectForKeyedSubscript:(NSString * __nonnull)key;

/// See the documentation of <code>FilterFunction</code>.
@property (nonatomic, readonly, copy) MustacheBox * __nullable (^ __nullable filter)(MustacheBox * __nonnull, BOOL, NSError * __nullable * __null_unspecified);
@property (nonatomic, readonly, copy) MustacheBox * __nonnull (^ __nullable keyedSubscript)(NSString * __nonnull);
@end


@interface MustacheBox (SWIFT_EXTENSION(Mustache))

/// A textual representation of <code>self</code>, suitable for debugging.
@property (nonatomic, readonly, copy, getter=debugDescription) NSString * __nonnull debugDescription;
@end


@interface MustacheBox (SWIFT_EXTENSION(Mustache))

/// <code>MustacheBox</code> conforms to the <code>MustacheBoxable</code> protocol so that it can feed
/// Mustache templates. Its mustacheBox property returns itself.
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSDictionary (SWIFT_EXTENSION(Mustache))

/// <code>NSDictionary</code> can feed Mustache templates. It behaves exactly like Swift
/// dictionaries.
///
/// <blockquote><p>// Renders "Freddy Mercury"
/// let dictionary: NSDictionary = [</p><blockquote><p>"firstName": "Freddy",
/// "lastName": "Mercury"]</p></blockquote><p>let template = Template(string: "{{firstName}} {{lastName}}")!
/// let rendering = template.render(Box(dictionary))!</p></blockquote>
/// ### Rendering
///
/// <ul><li><p><code>{{dictionary}}</code> renders the result of the <code>description</code> method, HTML-escaped.</p></li><li><p><code>{{{dictionary}}}</code> renders the result of the <code>description</code> method, <em>not</em> HTML-escaped.</p></li><li><p><code>{{#dictionary}}...{{/dictionary}}</code> renders once, pushing <code>dictionary</code> on</p></li></ul>
/// the top of the context stack.
///
/// <ul><li><p><code>{{^dictionary}}...{{/dictionary}}</code> does not render.</p></li></ul>
/// In order to iterate over the key/value pairs of a dictionary, use the <code>each</code>
/// filter from the Standard Library:
///
/// <blockquote><p>// Attach StandardLibrary.each to the key "each":
/// let template = Template(string: "<{{# each(dictionary) }}{{@key}}:{{.}}, {{/}}>")!
/// template.registerInBaseContext("each", Box(StandardLibrary.each))</p><p>// Renders "<name:Arthur, age:36, >"
/// let dictionary = ["name": "Arthur", "age": 36] as NSDictionary
/// let rendering = template.render(Box(["dictionary": dictionary]))!</p></blockquote>
/// ### Unwrapping from MustacheBox
///
/// Whenever you want to extract a dictionary of a MustacheBox, use the
/// `dictionaryValue` property: it reliably returns an <code>[String: MustacheBox]</code>
/// dictionary, whatever the actual type of the raw boxed value.
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSFormatter (SWIFT_EXTENSION(Mustache))

/// <code>NSFormatter</code> can be used as a filter:
///
/// <blockquote><p>let percentFormatter = NSNumberFormatter()
/// percentFormatter.numberStyle = .PercentStyle</p><p>var template = Template(string: "{{ percent(x) }}")!
/// template.registerInBaseContext("percent", Box(percentFormatter))</p><p>// Renders "50%"
/// template.render(Box(["x": 0.5]))!</p></blockquote>
/// <code>NSFormatter</code> can also format all variable tags in a Mustache section:
///
/// <blockquote><dl><dt>template = Template(string:</dt><dd><dl><dt>"{{# percent }}" +</dt><dd><dl><dt>"{{#ingredients}}" +</dt><dd><p>"- {{name}} ({{proportion}})\n" +</p></dd></dl><p>"{{/ingredients}}" +</p></dd></dl><p>"{{/percent}}")!</p></dd></dl><p>template.registerInBaseContext("percent", Box(percentFormatter))</p><p>// - bread (50%)
/// // - ham (35%)
/// // - butter (15%)
/// var data = [</p><blockquote><dl><dt>"ingredients":[</dt><dd><p>["name": "bread", "proportion": 0.5],
/// ["name": "ham", "proportion": 0.35],
/// ["name": "butter", "proportion": 0.15]]]</p></dd></dl></blockquote><p>template.render(Box(data))!</p></blockquote>
/// As seen in the example above, variable tags buried inside inner sections are
/// escaped as well, so that you can render loop and conditional sections.
/// However, values that can't be formatted are left untouched.
///
/// Precisely speaking, "values that can't be formatted" are the ones for which
/// the <code>-[NSFormatter stringForObjectValue:]</code> method return nil, as stated by
/// NSFormatter documentation https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSFormatter_Class/index.html#//apple_ref/occ/instm/NSFormatter/stringForObjectValue:
///
/// Typically, <code>NSNumberFormatter</code> only formats numbers, and <code>NSDateFormatter</code>,
/// dates: you can safely mix various data types in a section controlled by
/// those well-behaved formatters.
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSNull (SWIFT_EXTENSION(Mustache))

/// <code>NSNull</code> can feed Mustache templates.
///
/// ### Rendering
///
/// <ul><li><p><code>{{null}}</code> does not render.</p></li><li><p><code>{{#null}}...{{/null}}</code> does not render (NSNull is falsey).</p></li><li><p><code>{{^null}}...{{/null}}</code> does render (NSNull is falsey).</p></li></ul>
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSNumber (SWIFT_EXTENSION(Mustache))

/// <code>NSNumber</code> can feed Mustache templates. It behaves exactly like Swift
/// numbers: depending on its internal objCType, an NSNumber is rendered as a
/// Swift Bool, Int, UInt, or Double.
///
/// ### Rendering
///
/// <ul><li><p><code>{{number}}</code> is rendered with built-in Swift String Interpolation.
/// Custom formatting can be explicitly required with NSNumberFormatter, as in
/// `{{format(a)}}` (see <code>NSFormatter</code>).</p></li><li><p><code>{{#number}}...{{/number}}</code> renders if and only if <code>number</code> is not 0 (zero).</p></li><li><p><code>{{^number}}...{{/number}}</code> renders if and only if <code>number</code> is 0 (zero).</p></li></ul>
/// ### Unwrapping from MustacheBox
///
/// Whenever you want to extract a number out of a MustacheBox, use the
/// intValue, uintValue, doubleValue or boolValue properties: they reliably
/// return the expected type whatever the actual type of the raw boxed value.
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSObject (SWIFT_EXTENSION(Mustache))

/// <code>NSObject</code> can feed Mustache templates.
///
/// NSObject's default implementation handles two general cases:
///
/// <ul><li><p>Enumerable objects that conform to the <code>NSFastEnumeration</code> protocol, such
/// as <code>NSArray</code> and <code>NSOrderedSet</code>.</p></li><li><p>All other objects</p></li></ul>
/// GRMustache ships with a few specific classes that escape the general cases
/// and provide their own rendering behavior: <code>NSDictionary, `NSFormatter</code>,
/// `NSNull`, <code>NSNumber</code>, <code>NSString</code>, and <code>NSSet</code> (see the documentation for
/// those classes).
///
/// Your own subclasses of NSObject can also override the <code>mustacheBox</code> method
/// and provide their own custom behavior.
///
/// ## Arrays
///
/// An object is treated as an array if it conforms to <code>NSFastEnumeration</code>. This
/// is the case of <code>NSArray</code> and <code>NSOrderedSet</code>, for example. <code>NSDictionary</code> and
/// `NSSet` have their own custom Mustache rendering: see their documentation
/// for more information.
///
/// ### Rendering
///
/// <ul><li><p><code>{{array}}</code> renders the concatenation of the renderings of the array items.</p></li><li><p><code>{{#array}}...{{/array}}</code> renders as many times as there are items in
/// `array`, pushing each item on its turn on the top of the context stack.</p></li><li><p><code>{{^array}}...{{/array}}</code> renders if and only if <code>array</code> is empty.</p></li></ul>
/// ### Keys exposed to templates
///
/// An array can be queried for the following keys:
///
/// <ul><li><p><code>count</code>: number of elements in the array</p></li><li><p><code>first</code>: the first object in the array</p></li><li><p><code>firstObject</code>: the first object in the array</p></li><li><p><code>last</code>: the last object in the array</p></li><li><p><code>lastObject</code>: the last object in the array</p></li></ul>
/// Because 0 (zero) is falsey, <code>{{#array.count}}...{{/array.count}}</code> renders
/// once, if and only if <code>array</code> is not empty.
///
/// ## Other objects
///
/// Other objects fall in the general case.
///
/// Their keys are extracted with the <code>valueForKey:</code> method, as long as the key
/// is a property names, a custom property getter, or the name of a
/// `NSManagedObject` attribute.
///
/// ### Rendering
///
/// <ul><li><p><code>{{object}}</code> renders the result of the <code>description</code> method, HTML-escaped.</p></li><li><p><code>{{{object}}}</code> renders the result of the <code>description</code> method, <em>not</em>
/// HTML-escaped.</p></li><li><p><code>{{#object}}...{{/object}}</code> renders once, pushing <code>object</code> on the top of
/// the context stack.</p></li><li><p><code>{{^object}}...{{/object}}</code> does not render.</p></li></ul>
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSSet (SWIFT_EXTENSION(Mustache))

/// <code>NSSet</code> can feed Mustache templates. It behaves exactly like Swift sets.
///
/// <blockquote><p>let set: NSSet = [1,2,3]</p><p>// Renders "213"
/// let template = Template(string: "{{#set}}{{.}}{{/set}}")!
/// template.render(Box(["set": Box(set)]))!</p></blockquote>
/// ### Rendering
///
/// <ul><li><p><code>{{set}}</code> renders the concatenation of the renderings of the set items, in</p></li></ul>
/// any order.
///
/// <ul><li><p><code>{{#set}}...{{/set}}</code> renders as many times as there are items in <code>set</code>,</p></li></ul>
/// pushing each item on its turn on the top of the context stack.
///
/// <ul><li><p><code>{{^set}}...{{/set}}</code> renders if and only if <code>set</code> is empty.</p></li></ul>
/// ### Keys exposed to templates
///
/// A set can be queried for the following keys:
///
/// <ul><li><p><code>anyObject</code>: the first object in the set</p></li><li><p><code>count</code>: number of elements in the set</p></li><li><p><code>first</code>: the first object in the set</p></li></ul>
/// Because 0 (zero) is falsey, <code>{{#set.count}}...{{/set.count}}</code> renders once,
/// if and only if <code>set</code> is not empty.
///
/// ### Unwrapping from MustacheBox
///
/// Whenever you want to extract a collection of a MustacheBox, use the
/// `arrayValue` property: it reliably returns an Array of MustacheBox, whatever
/// the actual type of the raw boxed value (Set, Array, NSArray, NSSet, ...)
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end


@interface NSString (SWIFT_EXTENSION(Mustache))

/// <code>NSString</code> can feed Mustache templates. It behaves exactly like Swift
/// strings.
///
/// ### Rendering
///
/// <ul><li><p><code>{{string}}</code> renders the string, HTML-escaped.</p></li><li><p><code>{{{string}}}</code> renders the string, <em>not</em> HTML-escaped.</p></li><li><p><code>{{#string}}...{{/string}}</code> renders if and only if <code>string</code> is not empty.</p></li><li><p><code>{{^string}}...{{/string}}</code> renders if and only if <code>string</code> is empty.</p></li></ul>
/// HTML-escaping of <code>{{string}}</code> tags is disabled for Text templates: see
/// `Configuration.contentType` for a full discussion of the content type of
/// templates.
///
/// ### Keys exposed to templates
///
/// A string can be queried for the following keys:
///
/// <ul><li><p><code>length</code>: the number of characters in the string (using Swift method).</p></li></ul>
/// ### Unwrapping from MustacheBox
///
/// Whenever you want to extract a string out of a box, cast the boxed value to
/// String or NSString:
///
/// <blockquote><p>let box = Box("foo")
/// box.value as! String     // "foo"
/// box.value as! NSString   // "foo"</p></blockquote>
/// If the box does not contain a String, this cast would fail. If you want to
/// process the rendering of a value ("123" for 123), consider looking at the
/// documentation of:
///
/// <ul><li><p><code>func Filter(filter: (Rendering, NSErrorPointer) -> Rendering?) -> FilterFunction</code></p></li><li><p><code>RenderFunction</code></p></li></ul>
@property (nonatomic, readonly) MustacheBox * __nonnull mustacheBox;
@end

#pragma clang diagnostic pop
