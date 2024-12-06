namespace editor;

public sealed partial class MainPage : Page
{
    public MainPage()
    {
        this
            .Background(ThemeResource.Get<Brush>("ApplicationPageBackgroundThemeBrush"))
            .Content(new StackPanel()
                .VerticalAlignment(VerticalAlignment.Center)
                .HorizontalAlignment(HorizontalAlignment.Left)
                .Children(
                    new TextBlock()
                        .Text("Bienvenido a GDV Engine").FontSize(24).Margin(30)
                ));
    }
}
