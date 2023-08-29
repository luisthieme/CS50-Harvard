import '../../css/styles.css'

interface socialObjects {
    id: number;
    socialName: string;
    socialLogo: string;
    socialLink: string;
    socialUsername: string;
}

interface socialCardProps {
    socialCard: socialObjects[];
}

export default function SocialCard ( props: socialCardProps) {
    return (
        <>
            {props.socialCard.map(socials => (
                <div className="socialCardContainer">
                    <h2 className="socialCardHeading">{ socials.socialName }</h2>
                    <img className="socialCardImg" src={ socials.socialLogo }/>
                    <a className="socialCardLink" href={ socials.socialLink }>{ socials.socialUsername }</a>
                </div>
            ))}
        </>
    );
}
